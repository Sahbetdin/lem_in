var graph;
var data;
var ants_out = 0;
var ants_total = 0;
var rounds = 0;
var pause = true;
var time_out = 0;

$(document).ready(function() {
    $.getJSON("data.json", function(data) {
        graph = cytoscape({
            container: $("#graph"),
            elements: data,
            layout: { name: "cose-bilkent" },
            style: [
                {
                    selector: "node",
                    style: {
                        content: "data(id)",
                        "font-size": "10px",
                        "font-family": "Monaco",
                        "text-valign": "center",
                        "text-halign": "center",
                        "background-color": "#232b2b",
                        color: "#fff",
                        "overlay-padding": "6px",
                        "z-index": "10",
                        opacity: "0.3"
                    }
                },
                {
                    selector: "edge",
                    style: {
                        "line-color": "#353839",
                        "overlay-padding": "3px",
                        "curve-style": "straight",
                        opacity: "0.03"
                    }
                }
            ]
        });
        var width = graph.nodes('node[type = "start"]').style("width");
        var new_width = width.substr(0, width.length - 2) * 1.3 + "px";
        graph.nodes('node[type = "start"]').style({
            "background-color": "#ffffff",
            "border-style": "solid",
            "border-color": "#fff",
            "border-width": "5px",
            color: "#000000",
            opacity: "1",
            width: new_width,
            height: new_width
        });
        graph.nodes('node[type = "end"]').style({
            "background-color": "#ffffff",
            "border-style": "solid",
            "border-color": "#fff",
            "border-width": "5px",
            color: "#000000",
            width: new_width,
            height: new_width
        });
        var i = 0;
        var all_started;
        var ants_on_paths = new Array(data.paths.length);

        $("#paths").text("Paths: " + data.paths_count);
        $("#ants_out").text("Ants out: " + ants_out + "/" + data.ants);
        $("#rounds").text("Rounds: " + rounds);
        data.paths.forEach(function(path, p) {
            ants_total += path.ants;
            color_path(path.nodes, i);
            ants_on_paths[p] = path.ants;
            i++;
        });

        $("#next").click(function() {
            if (ants_out < ants_total) {
                all_started = true;
                data.paths.forEach(function(path, p) {
                    for (i = path.nodes.length - 2; i > 0; i--) {
                        if (graph.getElementById(path.nodes[i]).style("opacity") == 1) {
                            move_ant(path.nodes[i], path.nodes[i + 1], data.ants);
                            for (i = 1; i < path.nodes.length; i++) {
                                if (get_edge_opacity(path.nodes[i - 1], path.nodes[i]) == 1) {
                                    graph.getElementById(path.nodes[i]).style("opacity", 0.3);
                                    set_edge_opacity(path.nodes[i - 1], path.nodes[i], 0.03);
                                    break;
                                }
                            }
                            break;
                        }
                    }
                    if (
                        ants_on_paths[p] > 0 &&
                        get_edge_opacity(path.nodes[0], path.nodes[1]) < 1
                    ) {
                        move_ant(path.nodes[0], path.nodes[1], data.ants);
                        ants_on_paths[p] -= 1;
                        if (ants_on_paths[p] > 0) {
                            all_started = false;
                        }
                    }
                });
                if (all_started == true) {
                    graph.nodes('node[type = "start"]').style("opacity", 0.3);
                }
                rounds += 1;
                $("#rounds").text("Rounds: " + rounds);
            } else {
                graph.nodes().style("opacity", 0.3);
                graph.edges().style("opacity", 0.03);
                graph.nodes('node[type = "end"]').style("opacity", 1);
                document.getElementById("play_pause").style.color = "#999999";
                document.getElementById("next").style.color = "#999999";
            }
        });

        $("#reset").click(function() {
            if (pause == false)
            {
                pause = true;
                $("#play_pause").text("Play ");
            }
            ants_out = 0;
            rounds = 0;
            $("#ants_out").text("Ants out: " + ants_out + "/" + data.ants);
            $("#rounds").text("Rounds: " + rounds);
            data.paths.forEach(function(path, p) {
                for (i = 0; i < path.nodes.length; i++) {
                    graph.getElementById(path.nodes[i]).style("opacity", 0.3);
                    set_edge_opacity(path.nodes[i], path.nodes[i + 1], 0.03);
                }
                ants_on_paths[p] = path.ants;
            });
            graph.nodes('node[type = "start"]').style("opacity", 1);
            graph.nodes('node[type = "end"]').style("opacity", 0.3);
            document.getElementById("play_pause").style.color = "#111111";
            document.getElementById("next").style.color = "#111111";
        });

        $("#play_pause").click(function() {
            if (pause == true) {
                pause = false;
                $("#play_pause").text("Pause");
            } else {
                pause = true;
                $("#play_pause").text("Start");
            }
            play_pause();
        });
    });
});

function play_pause() {
    if (ants_out <= ants_total && pause == false) {
        time_out = 80;
        setTimeout(function() {
            $("#next").trigger("click");
            play_pause();
        }, time_out);
        if (ants_out == ants_total) {
            $("#play_pause").trigger("click");
        }
    }
}

function set_edge_opacity(node1, node2, value) {
    graph.edges()
        .filter(function(edge) {
            var e1 = edge.source().id() == node1 && edge.target().id() == node2;
            var e2 = edge.source().id() == node2 && edge.target().id() == node1;
            return e1 || e2;
        })
        .style("opacity", value);
}

function get_edge_opacity(node1, node2) {
    return graph
        .edges()
        .filter(function(edge) {
            var e1 = edge.source().id() == node1 && edge.target().id() == node2;
            var e2 = edge.source().id() == node2 && edge.target().id() == node1;
            return e1 || e2;
        })
        .style("opacity");
}

function move_ant(node1, node2, total_ants) {
    graph.nodes('node[id = "' + node2 + '"]').style("opacity", 1);
    set_edge_opacity(node1, node2, 1);
    console.log(node1 + "->" + node2);
    if (node2 == graph.nodes('node[type = "end"]').id()) {
        ants_out += 1;
        $("#ants_out").text("Ants out: " + ants_out + "/" + total_ants);
    }
}

function color_path(nodes, i) {
    var j;
    var color;

    var samples = [0,1,2,3,4,5,6,7,8,9,'a','b','c','d','e','f']
    var str = '#'
    for (var i=0;i<6;i++){
        str += samples[Math.floor(Math.random()*samples.length)];
    }
    color = str
    console.log(color)

    for (j = 0; j < nodes.length; j++) {
        if (
            nodes[j] != graph.nodes('node[type = "start"]').id() &&
            nodes[j] != graph.nodes('node[type = "end"]').id()
        ) {
            room = nodes[j];
            graph.nodes('node[id = "' + nodes[j] + '"]').style(
                "background-color",
                color
            );
        }
        graph.edges()
            .filter(function(edge) {
                var e1 =
                    edge.source().id() == nodes[j] && edge.target().id() == nodes[j + 1];
                var e2 =
                    edge.source().id() == nodes[j + 1] && edge.target().id() == nodes[j];
                return e1 || e2;
            })
            .style("line-color", color)
            .style("opacity", 0.03);
    }
}
