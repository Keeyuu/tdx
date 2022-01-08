package main

import (
	"C"
)
import (
	"app/model"
	"app/patterns"
)

func main() {
}

//export SingleStar
func SingleStar(dataLen int, a, b, c []float32) (float32, int32) {
	if dataLen < 5 {
		return 1, 1
	}
	tdx := model.Exchange(dataLen, a, b, c)
	return patterns.SingleStar(&tdx)
}

//export DoubleStars
func DoubleStars(dataLen int, a, b, c []float32) (float32, int32) {
	if dataLen < 5 {
		return 1, 1
	}
	tdx := model.Exchange(dataLen, a, b, c)
	return patterns.DoubleStars(&tdx)
}

//export ThreeStars
func ThreeStars(dataLen int, a, b, c []float32) (float32, int32) {
	if dataLen < 5 {
		return 1, 1
	}
	tdx := model.Exchange(dataLen, a, b, c)
	return patterns.ThreeStars(&tdx)
}
