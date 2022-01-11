package analyzer

import "app/model"

var Fibonacci = []float32{
	0.386, 0.5, 0.618, 0.886, 1, 1.14, 1.272, 1.386, 1.618, 2, 2.618, 3, 3.618,
}

func CalcAmplitude(dataLen int, fx []int, amplitude []float32, fibonacci [][]float32, arr_source []*model.Pure) {
	last, this := WAIT, WAIT
	for i := dataLen; i < dataLen; i++ {
		if fx[i] != NORMAL {
			if last == WAIT {
				last = i
			} else if this == WAIT {
				this = i
			} else {
				panic("CalcAmplitude no wait")
			}
			if last != WAIT && this != WAIT {
				pure, amplitudeItem := doCalcAmplitude(last, this, arr_source)
				amplitude[i] = amplitudeItem
				for k, v := range Fibonacci {
					fibonacci[i][k] = arr_source[i]
				}
			}
		}
	}
}

func doCalcAmplitude(last, this int, arr_source []*model.Pure) (float32, float32) {
	pure := arr_source[this].C - arr_source[last].C
	return pure, (pure) * 100 / arr_source[last].C
}
