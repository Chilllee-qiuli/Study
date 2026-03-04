TopoResultTopoKahn::runWithOrder(const Graph &dag, const vector<int> &order)
{
    // 初始化步骤：记录所有节点入度
    steps.push_back({StepType::TopoInitIndeg, ...});
    int pos = 1;
    for (int u : order){
        steps.push_back({StepType::TopoDequeue, u, ...});
        for (int v : dag.adj[u]){
            indeg[v]--;
            steps.push_back({StepType::TopoIndegDec, u, v, ...});
            if (indeg[v] == 0) steps.push_back({StepType::TopoEnqueue, v, ...});
        }
    }
    return result;
}
