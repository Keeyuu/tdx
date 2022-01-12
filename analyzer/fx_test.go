package analyzer

import (
	"app/model"
	"encoding/json"
	"io/ioutil"
	"os"
	"testing"
)

type Data struct {
	Close float32 `json:"close"`
	High  float32 `json:"high"`
	Low   float32 `json:"low"`
}

func ExchangePure(in []Data) []*model.Pure {
	arr := make([]*model.Pure, 0, len(in))
	for i, item := range in {
		arr = append(arr, &model.Pure{
			C: item.Close,
			H: item.High,
			L: item.Low,
			Range: model.IndexRange{
				R: i,
				L: i,
			},
		})
	}
	return arr
}

func Test_FindFx(t *testing.T) {
	fd, _ := os.OpenFile("./cache.json", os.O_RDONLY, 0664)
	by, _ := ioutil.ReadAll(fd)
	data := make([]Data, 0)
	if err := json.Unmarshal(by, &data); err != nil {
		t.Error(string(by))
	}
	tdx := ExchangePure(data)
	arr := Fx(tdx)
	a := make([]float32, len(tdx))
	b := make([][]float32, len(tdx))
	for i, _ := range b {
		b[i] = make([]float32, 20)
	}
	CalcAmplitude(len(tdx), arr, a, b, tdx)
	t.Error(b)
}
