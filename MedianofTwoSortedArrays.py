"""
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

"""

class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        N1 = len(nums1)
        N2 = len(nums2)
        
        left_index1 = (N1 - 1) / 2
        left_index2 = (N2 - 1) / 2
        right_index1 = N1 / 2
        right_index2 = N2 / 2

        if N1 == 0 or N2 == 0:
            return False

        if N1 <= 2 and N2 <= 2:
            left = max(nums1[0], nums2[0])
            if N1 == N2 == 2:
                right = min(nums1[1], nums2[1])
                return (left+right) / float(2)
            elif N1 == 1 and N2 == 2:
                return left
            elif N1 == 2 and N1 == 1:
                return left            

        median1 = (nums1[left_index1] + nums1[right_index1] ) / float(2)
        median2 = (nums2[left_index2] + nums2[right_index2] ) / float(2)

        if median1 == median2:
            return median1
        elif median1 < median2:
            l1 = nums1[left_index1: ]
            l2 = nums2[ :right_index2+1]
            print l1, l2
        elif median2 < median1:
            l1 = nums2[right_index2: ]
            l2 = nums1[ :left_index1+1]
            print l1, l2

        return self.findMedianSortedArrays(l1, l2)
        

if __name__ == "__main__":
    l1 = [1, 3, 5, 7]
    l2 = [2, 4, 5, 7]
    sol = Solution()
    print sol.findMedianSortedArrays(l1, l2)