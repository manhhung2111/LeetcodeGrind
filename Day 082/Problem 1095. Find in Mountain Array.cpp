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

    int findPeakIndex(MountainArray &mountainAr) {
        int left = 1, right = mountainAr.length() - 2;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            int numMid = mountainAr.get(mid);
            int prev = mountainAr.get(mid - 1);
            int next = mountainAr.get(mid + 1);
            if (numMid > prev && numMid > next) {
                return mid;
            } else if (numMid < next) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peakIndex = findPeakIndex(mountainArr);
        if (mountainArr.get(peakIndex) == target) return peakIndex;
        int left = 0, right = peakIndex - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int num = mountainArr.get(mid);
            if (num == target) {
                return mid;
            } else if (num > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        left = peakIndex + 1, right = mountainArr.length() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int num = mountainArr.get(mid);
            if (num == target) {
                return mid;
            } else if (num > target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }
};