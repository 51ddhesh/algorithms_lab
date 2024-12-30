package main

import (
	"bufio"
	"encoding/csv"
	"fmt"
	"math/rand"
	"os"
	"strconv"
	"time"
)

// Merge function merges two sorted subarrays into a single sorted array.
func merge(arr []int, left, mid, right int) {
	// Create temporary arrays to hold the two subarrays
	leftSize := mid - left + 1
	rightSize := right - mid
	leftArr := make([]int, leftSize)
	rightArr := make([]int, rightSize)

	// Copy data into temporary arrays
	copy(leftArr, arr[left:mid+1])
	copy(rightArr, arr[mid+1:right+1])

	// Merge the temporary arrays back into the original array
	i, j, k := 0, 0, left
	for i < leftSize && j < rightSize {
		if leftArr[i] <= rightArr[j] {
			arr[k] = leftArr[i]
			i++
		} else {
			arr[k] = rightArr[j]
			j++
		}
		k++
	}

	// Copy any remaining elements of leftArr[] or rightArr[]
	for i < leftSize {
		arr[k] = leftArr[i]
		i++
		k++
	}
	for j < rightSize {
		arr[k] = rightArr[j]
		j++
		k++
	}
}

// MergeSort function recursively splits the array into halves and sorts them
func mergeSort(arr []int, left, right int) {
	if left < right {
		mid := left + (right-left)/2

		// Recursively sort the two halves
		mergeSort(arr, left, mid)
		mergeSort(arr, mid+1, right)

		// Merge the sorted halves
		merge(arr, left, mid, right)
	}
}

func main() {
	// Open the input file (in.txt) for reading
	inputFile, err := os.Open("in.txt")
	if err != nil {
		fmt.Println("Error opening input file:", err)
		return
	}
	defer inputFile.Close()

	// Create the output CSV file (data.csv) for writing
	outputFile, err := os.Create("data.csv")
	if err != nil {
		fmt.Println("Error creating output file:", err)
		return
	}
	defer outputFile.Close()

	// Create a CSV writer
	writer := csv.NewWriter(outputFile)
	defer writer.Flush()

	// Write the header to the CSV file
	writer.Write([]string{"Input_Size", "Time"})

	// Read the input file line by line
	var inputSizes []int
	// Scan the input sizes (one per line)
	scanner := bufio.NewScanner(inputFile)
	for scanner.Scan() {
		line := scanner.Text()
		// Convert each line to an integer and store in inputSizes
		size, err := strconv.Atoi(line)
		if err != nil {
			fmt.Println("Invalid input in in.txt:", err)
			return
		}
		inputSizes = append(inputSizes, size)
	}

	// Set up random number generation (between -100000 and 100000)
	rand.Seed(time.Now().UnixNano())
	min := -100000
	max := 100000
	rangeLimit := max - min

	// Iterate through each input size, generate the corresponding array, and sort it
	for _, n := range inputSizes {
		// Generate a slice with n random integers
		arr := make([]int, n)
		for i := 0; i < n; i++ {
			arr[i] = rand.Intn(rangeLimit) + min
		}

		// Measure the time taken for merge sort
		start := time.Now()
		mergeSort(arr, 0, len(arr)-1)
		duration := time.Since(start)

		// Write the input size and time to the CSV file
		writer.Write([]string{strconv.Itoa(n), fmt.Sprintf("%f", duration.Seconds())})
	}

	fmt.Println("Merge sort execution completed, results saved to data.csv")
}
