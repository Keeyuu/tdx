package analyzer

import (
	"app/model"
	"testing"
)

func Test_FindFx(t *testing.T) {
	a := []float32{2, 1, 2, 2, 2, 2, 1, 2, 8, 1}
	tdx := model.ExchangePure(10, a, a, a)
	arr := Fx(tdx)
	t.Error(arr)
}
