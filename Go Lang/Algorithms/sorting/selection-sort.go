package main

import "fmt"

func main() {
    var n = []int{1, 39, 2, 9, 7, 54, 11}

    var i = 1
    for i < len(n) - 1 {
        var j = i + 1
        var minIndex = i

        if j < len(n) {
            if n[j] < n[minIndex] {
                minIndex = j
            }
            j++
        }

        if minIndex != i {
            var temp = n[i]
            n[i] = n[minIndex]
            n[minIndex] = temp
        }

        i++
    }

    fmt.Println(n)
}