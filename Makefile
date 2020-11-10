build_Dijkstra:
	g++ Dijkstra.cpp -o Dijkstra.exe
build_Bellman_Ford_Distance:
	g++ Bellman-Ford-Distance.cpp -o Bellman-Ford-Distance.exe
build_Bellman_Ford_Negative_Cycle:
	g++ Bellman-Ford-Negative-Cycle.cpp -o Bellman-Ford-Negative-Cycle.exe	
run_Dijkstra:
	./Dijkstra.exe
run_Dijkstra_Default:
	./Dijkstra.exe < in_distance
run_Bellman_Ford_Distance:
	./Bellman-Ford-Distance.exe
run_Bellman_Ford_Distance_Default:
	./Bellman-Ford-Distance.exe < in_distance_negative
run_Bellman_Ford_Negative_Cycle:
	./Bellman-Ford-Negative-Cycle.exe
run_Bellman_Ford_Negative_Cycle_Default:
	./Bellman-Ford-Negative-Cycle.exe < in_negative_cycle

build_all: build_Bellman_Ford_Distance build_Bellman_Ford_Negative_Cycle build_Dijkstra

clean:
	rm *.exe && rm *.out