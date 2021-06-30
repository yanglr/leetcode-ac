package main

import (
	"fmt"
	"sort"
)

// Test
func main() {
	input := []int{3, 2, 1, 5, 6, 4}
	res := findKthLargest(input, 2)
	fmt.Printf("%d\n", res)
}

// Submit to leetcode
func findKthLargest(nums []int, k int) int {
	// 排序
	sort.Ints(nums)
	return nums[len(nums)-k]
}
