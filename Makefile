build_Dijkstra:
	g++ Dijkstra.cpp -o Dijkstra.exe
build_Bellman_Ford:
	g++ Bellman-Ford.cpp -o Bellman-Ford.exe
run_Dijkstra:
	./Dijkstra.exe
run_Dijkstra_Default:
	./Dijkstra.exe < in
run_Bellman_Ford:
	./Bellman.exe
run_Bellman_Ford_Default:
	./Bellman.exe < in