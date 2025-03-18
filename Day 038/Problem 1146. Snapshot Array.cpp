class SnapshotArray {
public:
    vector<vector<pair<int, int>>> updates;
    int snapshotId = 0;

    SnapshotArray(int length) {
        updates.resize(length);
        snapshotId = 0;
    }
    
    void set(int index, int val) {
        // Overwrite value in the same index within the snapshot id
        if (!updates[index].empty() && updates[index].back().first == snapshotId) {
            updates[index].back().second = val;
        } else {
            updates[index].push_back({snapshotId, val});
        }
    }
    
    int snap() {
        return snapshotId++;
    }
    
    int get(int index, int snap_id) {
        if (updates[index].size() == 0) return 0;
        if (updates[index][0].first > snap_id) return 0;

        int low = 0, high = updates[index].size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (updates[index][mid].first == snap_id) {
                return updates[index][mid].second;
            } else if (updates[index][mid].first > snap_id) {
                high = mid - 1;
            } else if (updates[index][mid].first < snap_id) {
                low = mid + 1;
            }
        }

        if (high == -1) return 0; // No valid snapshot before snap_id
        return updates[index][high].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
