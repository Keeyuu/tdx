package tool

import (
	"fmt"
	"testing"
)

func Test_All(t *testing.T) {
	l := make(chan int, 10)
	l <- 1
	fmt.Println(len(l))
}

func Test_Ma(t *testing.T) {
	// 1,2,3,4 = 2.5
	ma := NewMa(4)
	fmt.Println(ma.Get())
	for i := 0; i < 5; i++ {
		ma.Add(float32(i))
	}
	fmt.Println(ma.Get())
	//2,3,4,5 = 3.5
	ma.Add(float32(5))
	fmt.Println(ma.Get())
}

func Test_Grow(t *testing.T) {
	l := []float32{1, 1.2, 2, 3}
	//// 50
	//grow := GetGrow(l, 0)
	//if grow != 50 {
	//	t.Error(grow)
	//}
	////100
	//grow = GetGrow(l, 1)
	//if grow != 100 {
	//	t.Error(grow)
	//}
	grow := GetGrow(l, 2)
	if grow != 100 {
		t.Error(grow)
	}
}

func Test_PureMa(t *testing.T) {
	l := []float32{1, 2, 3}
	ma := PureLastMa(l, 1)
	if ma != 3 {
		t.Error(ma)
	}
	ma = PureLastMa(l, 2)
	if ma != 2.5 {
		t.Error(ma)
	}
	ma = PureLastMa(l, 3)
	if ma != 2 {
		t.Error(ma)
	}
	ma = PureLastMa(l, 4)
	if ma != 2 {
		t.Error(ma)
	}
}

func Test_Max(t *testing.T) {
	l := []float32{100, 1, 2, 3, 2}
	m := GetMax(l, 2)
	if m != 3 {
		t.Error(m)
	}
	m = GetMax(l, 3)
	if m != 3 {
		t.Error(m)
	}
	m = GetMax(l, 5)
	if m != 100 {
		t.Error(m)
	}
	m = GetMax(l, 15)
	if m != 100 {
		t.Error(m)
	}
}

func change(l []int) {
	l[1] = 99
}

func Test_Slice(t *testing.T) {
	arr := []int{1, 2}
	change(arr)
	if arr[1] != 99 {
		t.Error(arr)
	}
}
