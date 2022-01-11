package analyzer

import (
	"app/model"
	"testing"
)

func Test_FindFx(t *testing.T) {
	a := []float32{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
	b := []float32{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
	c := []float32{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
	tdx := model.ExchangePure(9, a, b, c)
	arr := Fx(tdx)
	t.Error(arr)
}
