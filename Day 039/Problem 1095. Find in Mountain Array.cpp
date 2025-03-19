/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int low = 1, high = mountainArr.length() - 2;

        int peakIndex;
        while (low <= high) {
            int mid = low + (high - low)/2;

            int curr = mountainArr.get(mid);
            int prev = mountainArr.get(mid - 1);
            int next = mountainArr.get(mid + 1);
            if (curr > prev && curr > next) {
                peakIndex = mid;
                break;
            } else if (curr > prev){
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        low = 0, high = peakIndex;  
        while (low <= high) {
            int mid = low + (high - low)/2;

            int value = mountainArr.get(mid);
            if (value == target) {
                return mid;
            } else if (value > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        low = peakIndex, high =  mountainArr.length() - 1;
        while (low <= high) {
            int mid = low + (high - low)/2;

            int value = mountainArr.get(mid);
            if (value == target) {
                return mid;
            } else if (value < target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return -1;
    }
};