class Solution {
public:

    vector<char> choices = {'A', 'C', 'G', 'T'};
    vector<string> getNeighbours(string gene) {
        vector<string> neighbours;
        for (int i = 0; i < gene.size(); i++) {
            string temp = gene;
            for (int j = 0; j < choices.size(); j++) {
                if (gene[i] == choices[j]) {
                    continue;
                }
                temp[i] = choices[j];
                neighbours.push_back(temp);
            }
        }

        return neighbours;
    }


    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> geneBank(bank.begin(), bank.end());
        if (geneBank.find(endGene) == geneBank.end()) {
            return -1;
        }

        unordered_set<string> visited;

        queue<string> q;
        q.push(startGene);
        visited.insert(startGene);

        int step = 0;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                string gene = q.front(); q.pop();
                vector<string> neighbours = getNeighbours(gene);
                for (string neighbour : neighbours) {
                    if (visited.find(neighbour) == visited.end() && geneBank.find(neighbour) != geneBank.end()) {
                        q.push(neighbour);
                        visited.insert(neighbour);

                        if (endGene == neighbour) {
                            return ++step;
                        }
                    }
                }
            }
            step++;
        }

        return -1;
    }
};