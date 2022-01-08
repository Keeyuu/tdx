package analyzer

import "app/model"

func Fx(arr []*model.Pure) []*model.Fx {
	arr = contain(arr)
	fx := findFx(arr)
	return filterFx(fx)
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
			cache = arr[i]
		}
	}
	if cache != nil {
		arr_new = append(arr_new, cache)
	}
	return arr_new
}

func findFx(arr []*model.Pure) []*model.Fx {
	long := len(arr)
	arr_fx := make([]*model.Fx, 0, long/3)
	for i := 1; i < long-1; i++ {
		if checkH(arr[i-1], arr[i], arr[i+1]) {
			arr_fx = append(arr_fx, &model.Fx{K: *arr[i], Type: model.H})
		}
		if checkL(arr[i-1], arr[i], arr[i+1]) {
			arr_fx = append(arr_fx, &model.Fx{K: *arr[i], Type: model.L})
		}
	}
	return arr_fx
}

func filterFx(arr []*model.Fx) []*model.Fx {
	validFx := make([]*model.Fx, 0, len(arr)/2)
	for {
		if doFilterFx(arr) {
			break
		}
	}
	for _, item := range arr {
		if item != nil {
			validFx = append(validFx, item)
		}
	}
	return validFx
}

func doFilterFx(arr []*model.Fx) bool {
	this, next := -1, -1
	for i := 0; i < len(arr); i++ {
		if arr[i] != nil {
			if this == -1 {
				this = i
			} else if next != -1 {
				next = i
			} else {
				panic("this and next both != -1")
			}
		}
		if this != -1 && next != -1 {
			if validFxValue(arr[this], arr[next]) {
				switch validFxTime(arr[this], arr[next]) {
				case 0:
					this = -1
					next = -1
					continue
				case 1:
					arr[this] = nil
				case -1:
					arr[next] = nil
				}
				return false //一旦时间维度出现问题需要全部出现计算,因为时间的错误会蔓延
			} else {
				arr[this] = nil
				this = next
				next = -1
			}
		}
	}
	return true
}

func checkH(last, this, next *model.Pure) bool {
	return this.H > last.H && this.H > next.H
}
func checkL(last, this, next *model.Pure) bool {
	return this.L < last.L && this.L < next.L
}

func validFxValue(this, next *model.Fx) bool {
	switch this.Type {
	case model.H:
		return this.K.CalcValueH() > next.K.CalcValueH()
	case model.L:
		return this.K.CalcValueL() < next.K.CalcValueL()
	default:
		panic("type err")
	}
}

func validFxTime(this, next *model.Fx) int {
	// todo
	return 0
}
