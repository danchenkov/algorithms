package linked_list

import "testing"

func TestAdd(t *testing.T) {
    tests := []struct {
        a, b     int
        expected int
    }{
        {2, 3, 5},
        {0, 0, 0},
        {-1, -1, -2},
        {10, -5, 5},
    }

    for _, tt := range tests {
        result := Add(tt.a, tt.b)
        if result != tt.expected {
            t.Errorf("Add(%d, %d) = %d; want %d", tt.a, tt.b, result, tt.expected)
        }
    }
}
