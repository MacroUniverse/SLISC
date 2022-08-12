#include "../SLISC/graph.h"

void test_graph()
{
	// convert edges to/from text
	using namespace slisc;
	{
		vector<DWGnode> dwg;
		vector<vector<Long>> edges, edges2;
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
		vector<vector<Long>> edges, edges2;
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
}
