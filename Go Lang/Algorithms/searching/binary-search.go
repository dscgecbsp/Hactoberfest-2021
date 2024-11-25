package main

import "fmt"

func binarySearch(arr []int, s int) int {
    var leftPointer = 0
    var rightPointer = len(arr) - 1
    for leftPointer <= rightPointer {
        var midPointer = int((leftPointer + rightPointer) / 2)
        var midValue = arr[midPointer]

        if midValue == s {
            return midPointer
        } else if midValue < s {
            leftPointer = midPointer + 1
        } else {
            rightPointer = midPointer - 1
        }
    }

    return -1
}

func main() {
    var n = []int{2, 9, 11, 21, 22, 32, 36, 48, 76}

    fmt.Println(binarySearch(n, 32))
}