#include "../SLISC/algo/graph.h"

int main()
{
	// convert edges to/from text
	using namespace slisc;
	{
		vector<DWGnode> dwg;
		vector<DWGedge> edges, edges2;
		vector<Long> dists, dists2;
		dwg_rand_unsafe(edges, 20, 50, {-2,17}, 3);
		string text = dwg_edges2text(edges);
		dwg_text2edges(edges2, text);
		string text2 = dwg_edges2text(edges2);
		SLS_ASSERT(text == text2);
	}

	// SPF algo
	{
		vector<DWGnode> dwg;
		vector<DWGedge> edges, edges2;
		vector<Long> dists, dists2;
		dwg_rand(edges, 20, 50, {-2,17}, 3);
		// dwg_text2edges(edges, "0 2 4\n3 1 -1\n4 9 0\n2 3 3\n9 1 4\n8 7 -2\n1 0 2\n3 6 4\n6 7 -1\n4 0 2\n6 9 -1\n2 9 4\n0 3 -1\n9 5 -2\n3 5 2\n6 0 -2\n");
		edges2dwg(dwg, edges);
		// cout << dwg_edges2text(edges) << endl;

		for (Long source = 0; source < (Long)dwg.size(); ++source) {
			dwg_SPFA(dists, dwg, source);
			dwg_SPFA2(dists2, dwg, source);
			SLS_ASSERT(dists == dists2);
		}
	}

	// all/num paths from source to target
	{
		vector<DGnode> dag;
		for (Long i = 0; i <= 2; ++i) {
			dag_examp(dag, i);
			for (Long from = 0; from < (Long)dag.size(); ++from) {
				for (Long to = 0; to < (Long)dag.size(); ++to) {
					Long num = dag_num_paths(dag, from, to);
					vector<vector<Long>> paths;
					dag_all_paths(paths, dag, from, to);
					if(num != (Long)paths.size())
						SLS_FAIL;
				}
			}
		}
	}

	// minimum span tree of a graph
	{
		vector<DWGedge> g;

		// making above shown graph
		dwg_add_edge(g, 0, 1, 4);
		dwg_add_edge(g, 0, 7, 8);
		dwg_add_edge(g, 1, 2, 8);
		dwg_add_edge(g, 1, 7, 11);
		dwg_add_edge(g, 2, 3, 7);
		dwg_add_edge(g, 2, 8, 2);
		dwg_add_edge(g, 2, 5, 4);
		dwg_add_edge(g, 3, 4, 9);
		dwg_add_edge(g, 3, 5, 14);
		dwg_add_edge(g, 4, 5, 10);
		dwg_add_edge(g, 5, 6, 2);
		dwg_add_edge(g, 6, 7, 1);
		dwg_add_edge(g, 6, 8, 6);
		dwg_add_edge(g, 7, 8, 7);

		vector<Long> inds;
		int tot_wt = wg_MST_kruskal(inds, g, 9); // kruskal algorithm
		vector<Long> inds1 = {0,1,2,3,4,6,8,10};
		SLS_ASSERT(inds == inds1);
		SLS_ASSERT(tot_wt == 37);
	}
}
