/*
 * @Date: 2022-01-08 22:03:33
 * @LastEditors: Vscode
 * @LastEditTime: 2022-01-08 22:58:30
 * @Author: Keeyu
 * @Github: https://github.com/keeYuc
 */
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
