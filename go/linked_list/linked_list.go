package main

import "fmt"

type Node struct {
    next *Node
    data int
}

type LinkedList struct {
    head *Node
}

func (list *LinkedList) Print() {
    current := list.head
    for current != nil {
        fmt.Print(current.data)
        if current.next != nil {
            fmt.Print(" -> ")
        }
        current = current.next
    }
    fmt.Println()
}

func (list *LinkedList) String() (s string) {
    current := list.head
    for current != nil {
        s += fmt.Sprint(current.data)
        if current.next != nil {
            s += fmt.Sprint("->")
        }
        current = current.next
    }
    return s
}

func (list *LinkedList) Includes(value int) bool {
    if list.head == nil { return false }
    current := list.head
    for current != nil {
        if current.data == value {
            return true
        }
        current = current.next
    }
    return false
}

func (list *LinkedList) Prepend(data int) {
    list.head = &Node{next: list.head, data: data}
}

func main() {
    list := LinkedList{}
    list.Prepend(20)
    list.Prepend(10)
    list.Print()
}
