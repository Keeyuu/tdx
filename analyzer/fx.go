package analyzer

import (
	"app/model"
)

const (
	LOW = iota - 1
	NORMAL
	HIGH
	WAIT
	VALID
	SPECIAL_INDEX = 3
)

func Fx(arr []*model.Pure) []int {
	arr_new := contain(arr)
	fx := findFx(arr_new, arr)
	return filterFx(fx, arr)
}

func contain(arr []*model.Pure) []*model.Pure {
	long := len(arr)
	arr_new := make([]*model.Pure, 0, long)
	var cache *model.Pure
	for i := 0; i < long; i++ {
		if cache != nil {
			if cache.Contain(arr[i]) {
				cache.Range.R = arr[i].Range.R
			} else {
				arr_new = append(arr_new, cache)
				cache = nil
			}
		} else {
			cache = arr[i].CopyNew()
		}
	}
	if cache != nil {
		arr_new = append(arr_new, cache)
	}
	return arr_new
}

func findFx(arr, arr_origin []*model.Pure) []int {
	long := len(arr)
	arr_fx := make([]int, long)
	for i := 1; i < long-1; i++ {
		if checkHigh(arr[i-1], arr[i], arr[i+1]) && isSpecialHigh(arr[i], arr_origin) {
			arr_fx[i] = HIGH
		}
		if checkLow(arr[i-1], arr[i], arr[i+1]) && isSpecialLow(arr[i], arr_origin) {
			arr_fx[i] = LOW
		}
	}
	return arr_fx
}

func filterFx(arr []int, arr_origin []*model.Pure) []int {
	for {
		if doFilterFx(arr, arr_origin) {
			break
		}
	}
	return arr
}

func doFilterFx(arr []int, arr_origin []*model.Pure) bool {
	this, next := WAIT, WAIT
	for i := 0; i < len(arr); i++ {
		if this != WAIT && next != WAIT {
			if index := checkValid(this, next, arr_origin); index != VALID {
				arr[index] = NORMAL
				return false
			}
			this = next
			next = WAIT
		}
		if arr[i] != NORMAL {
			if this == WAIT {
				this = arr[i]
			} else if next == WAIT {
				next = arr[i]
			} else {
				panic("err")
			}
		}
	}
	return true
}

func checkValid(this, next int, arr_origin []*model.Pure) int {
	if this == next {
		if this == HIGH {
			if arr_origin[this].CalcValueHigh() >= arr_origin[next].CalcValueHigh() {
				return next
			}
			return this
		} else {
			if arr_origin[this].CalcValueLow() <= arr_origin[next].CalcValueLow() {
				return next
			}
			return this
		}
	} else {
		if arr_origin[this].Range.R+SPECIAL_INDEX > arr_origin[next].Range.L {
			return next
		}
	}
	return VALID
}

func checkHigh(last, this, next *model.Pure) bool {
	return this.CalcValueHigh() > last.CalcValueHigh() && this.CalcValueHigh() > next.CalcValueHigh()
}
func checkLow(last, this, next *model.Pure) bool {
	return this.CalcValueLow() < last.CalcValueLow() && this.CalcValueLow() < next.CalcValueLow()
}

func isSpecialHigh(this *model.Pure, arr []*model.Pure) bool {
	left, right := this.Range.L-SPECIAL_INDEX, this.Range.L+SPECIAL_INDEX
	if left < 0 {
		left = 0
	}
	if right > len(arr)-1 {
		right = len(arr) - 1
	}
	for i := left; i <= right; i++ {
		if arr[i].CalcValueHigh() > this.CalcValueHigh() {
			return false
		}
	}
	return true
}

func isSpecialLow(this *model.Pure, arr []*model.Pure) bool {
	left, right := this.Range.L-SPECIAL_INDEX, this.Range.L+SPECIAL_INDEX
	if left < 0 {
		left = 0
	}
	if right > len(arr)-1 {
		right = len(arr) - 1
	}
	for i := left; i <= right; i++ {
		if arr[i].CalcValueLow() < this.CalcValueLow() {
			return false
		}
	}
	return true
}
