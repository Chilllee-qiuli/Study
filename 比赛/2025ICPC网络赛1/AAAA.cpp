#include <bits/stdc++.h>
using namespace std;

struct Submission {
    string teamname;
    char problemid;
    int time;
    int result;
};

struct TeamData {
    int known_ac;
    int known_penalty;
    int known_rejections[26];
    bool solved[26];
    vector<int> unknown_times[26];
    TeamData() {
        known_ac = 0;
        known_penalty = 0;
        for (int i = 0; i < 26; i++) {
            known_rejections[i] = 0;
            solved[i] = false;
        }
    }
};

int main() {
    freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int sub;
        cin >> sub;
        vector<Submission> submissions(sub);
        for (int i = 0; i < sub; i++) {
            string result_str;
            cin >> submissions[i].teamname;
            cin >> submissions[i].problemid;
            cin >> submissions[i].time;
            cin >> result_str;
            if (result_str == "Accepted") {
                submissions[i].result = 1;
            } else if (result_str == "Rejected") {
                submissions[i].result = -1;
            } else {
                submissions[i].result = 0;
            }
        }

        map<string, TeamData> teams_map;

        for (auto &s : submissions) {
            string teamname = s.teamname;
            char problemid = s.problemid;
            int time = s.time;
            int result = s.result;
            int idx = problemid - 'A';
            TeamData &team = teams_map[teamname];
            if (time < 240) {
                if (result == 1) {
                    if (!team.solved[idx]) {
                        team.solved[idx] = true;
                        team.known_ac++;
                        team.known_penalty += time + 20 * team.known_rejections[idx];
                    }
                } else if (result == -1) {
                    if (!team.solved[idx]) {
                        team.known_rejections[idx]++;
                    }
                }
            } else {
                if (!team.solved[idx]) {
                    team.unknown_times[idx].push_back(time);
                }
            }
        }

        vector<string> team_names;
        vector<pair<int, int>> known_scores;
        vector<pair<int, int>> best_scores;

        for (auto &entry : teams_map) {
            string teamname = entry.first;
            TeamData &team = entry.second;
            team_names.push_back(teamname);
            int best_ac = team.known_ac;
            int best_penalty = team.known_penalty;
            for (int i = 0; i < 26; i++) {
                if (!team.solved[i] && !team.unknown_times[i].empty()) {
                    best_ac++;
                    int min_time = *min_element(team.unknown_times[i].begin(), team.unknown_times[i].end());
                    best_penalty += min_time + 20 * team.known_rejections[i];
                }
            }
            known_scores.push_back({team.known_ac, team.known_penalty});
            best_scores.push_back({best_ac, best_penalty});
        }

        int n = team_names.size();
        vector<string> candidates;
        for (int i = 0; i < n; i++) {
            bool valid = true;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (best_scores[i].first > known_scores[j].first) {
                    continue;
                } else if (best_scores[i].first == known_scores[j].first) {
                    if (best_scores[i].second <= known_scores[j].second) {
                        continue;
                    } else {
                        valid = false;
                        break;
                    }
                } else {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                candidates.push_back(team_names[i]);
            }
        }

        sort(candidates.begin(), candidates.end());
        for (size_t i = 0; i < candidates.size(); i++) {
            if (i > 0) cout << " ";
            cout << candidates[i];
        }
        cout << endl;
    }
    return 0;
}