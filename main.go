/*
 *                                                     __----~~~~~~~~~~~------___
 *                                    .  .   ~~//====......          __--~ ~~
 *                    -.            \_|//     |||\\  ~~~~~~::::... /~
 *                 ___-==_       _-~o~  \/    |||  \\            _/~~-
 *         __---~~~.==~||\=_    -_--~/_-~|-   |\\   \\        _/~
 *     _-~~     .=~    |  \\-_    '-~7  /-   /  ||    \      /
 *   .~       .~       |   \\ -_    /  /-   /   ||      \   /
 *  /  ____  /         |     \\ ~-_/  /|- _/   .||       \ /
 *  |~~    ~~|--~~~~--_ \     ~==-/   | \~--===~~        .\
 *           '         ~-|      /|    |-~\~~       __--~~
 *                       |-~~-_/ |    |   ~\_   _-~            /\
 *                            /  \     \__   \/~                \__
 *                        _--~ _/ | .-~~____--~-/                  ~~==.
 *                       ((->/~   '.|||' -_|    ~~-/ ,              . _||
 *                                  -_     ~\      ~~---l__i__i__i--~~_/
 *                                  _-~-__   ~)  \--______________--~~
 *                                //.-~~~-~_--~- |-------~~~~~~~~
 *                                       //.-~~~--\
 *                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 */

package main

import (
	"C"
	"unsafe"
)
import (
	"app/analyzer"
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

//export FindFx
func FindFx(dataLen int, a, b, c, d unsafe.Pointer) {
	if dataLen <= 3 {
		return
	}
	tdx := ExchangePure(dataLen, a, b, c)
	c_d := (*[1 << 28]C.float)(d)
	for i := 0; i < dataLen; i++ {
		c_d[i] = C.float(0)
	}
	for k, v := range analyzer.Fx(tdx) {
		c_d[k] = C.float(v)
	}
}

func ExchangePure(dataLen int, a, b, c unsafe.Pointer) []*model.Pure {
	c_a := (*[1 << 28]C.float)(a)
	c_b := (*[1 << 28]C.float)(b)
	c_c := (*[1 << 28]C.float)(c)
	arr := make([]*model.Pure, 0, dataLen)
	for i := 0; i < dataLen; i++ {
		item := new(model.Pure)
		item.C = float32(c_a[i])
		item.H = float32(c_b[i])
		item.L = float32(c_c[i])
		item.Range.L = i
		item.Range.R = i
		arr = append(arr, item)
	}
	return arr
}
