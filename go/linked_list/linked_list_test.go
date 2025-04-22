package main

import "testing"

func TestIncludes(t *testing.T) {
    tests := []struct {
        list LinkedList
        value int
        expected bool
    }{
        {LinkedList{&Node{nil, 10}}, 10, true},
        {LinkedList{&Node{nil, 20}}, 10, false},
        {LinkedList{}, 10, false},
        {LinkedList{&Node{&Node{nil, 20}, 10}}, 30, false},
        {LinkedList{&Node{&Node{&Node{nil, 30}, 20}, 10}}, 30, true},
    }

    for _, tt := range tests {
        result := tt.list.Includes(tt.value)
        if result != tt.expected {
            b1 := " not"
            b2 := ""
            if !result { b1 = ""; b2 = " not" }
            t.Errorf("Expected the list %s to%s include %d, but it did%s.", tt.list.String(), b1, tt.value, b2)
        }
    }
}
