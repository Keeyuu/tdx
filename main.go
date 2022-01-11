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
func FindFx(dataLen int, a, b, c, d []float32) {
	if dataLen < 5 {
		return
	}
	tdx := model.ExchangePure(dataLen, a, b, c)
	for k, v := range analyzer.Fx(tdx) {
		d[k] = float32(v)
	}
}
