/*
 * @Date: 2022-01-08 22:03:33
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2022-01-10 12:19:08
 * @Author: Keeyu
 * @Github: https://github.com/keeYuc
 */
package model

const (
	H              = "H"
	L              = "L"
	SPECIAL_WEIGHT = 0.8
	NORMAL_WEIGHT  = 1 - SPECIAL_WEIGHT
)

type Fx struct {
	K    Pure
	Type string
}

type Pure struct {
	C     float32
	H     float32
	L     float32
	Range IndexRange
}

type IndexRange struct {
	L int
	R int
}

func (p *Pure) Contain(next *Pure) bool {
	return p.H >= next.H && p.L <= next.H
}
func (p *Pure) CopyNew() *Pure {
	return &Pure{
		C:     p.C,
		H:     p.H,
		L:     p.H,
		Range: p.Range,
	}
}
func (p *Pure) CalcValueHigh() float32 {
	return p.C*NORMAL_WEIGHT + p.H*SPECIAL_WEIGHT
}
func (p *Pure) CalcValueLow() float32 {
	return p.C*NORMAL_WEIGHT + p.L*SPECIAL_WEIGHT
}

type Tdx struct {
	Len int
	InA []float32
	InB []float32
	InC []float32
}

func Exchange(dataLen int, a, b, c []float32) Tdx {
	return Tdx{
		Len: dataLen,
		InA: a,
		InB: b,
		InC: c,
	}
}

func ExchangePure(dataLen int, a, b, c []float32) []*Pure {
	arr := make([]*Pure, 0, dataLen)
	for i := 0; i < dataLen; i++ {
		item := new(Pure)
		item.C = a[i]
		item.H = b[i]
		item.L = c[i]
		item.Range.L = i
		item.Range.R = i
		arr = append(arr, item)
	}
	return arr
}
