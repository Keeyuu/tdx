package tool

type Ma struct {
	Len     int
	History chan float32
	Value   float32
}

func NewMa(long int) Ma { //生长的均线
	return Ma{
		Len:     long,
		History: make(chan float32, long+1),
		Value:   0.0,
	}
}

func (m *Ma) Add(f float32) {
	if len(m.History) >= m.Len {
		m.Value -= <-m.History
	}
	m.History <- f
	m.Value += f
}

func (m *Ma) Get() float32 {
	return m.Value / float32(m.Len)
}

func PureLastMa(l []float32, long int) (r float32) { //最后均线
	count := len(l)
	if count > long {
		count = long
	}
	for _, i := range l[len(l)-count:] {
		r += i
	}
	return r / float32(count)
}

func GetMax(l []float32, long int) float32 { //最高价
	var r float32 = -1
	count := len(l)
	if count > long {
		count = long
	}
	for _, i := range l[len(l)-count:] {
		if i > r {
			r = i
		}
	}
	return r
}

func GetMaxAndShift(l []float32, long int) (float32, int) { //最高价
	var r float32 = -1
	var i int = len(l)
	count := i
	if count > long {
		count = long
	}

	for index, value := range l[len(l)-count:] {
		if value > r {
			r = value
			i = count - index - 1
		}
	}
	return r, i
}

func GetMinCount(l []float32, long int) (low_index int) { //最低倒数序号
	var r float32 = 999999
	count := len(l)
	if count > long {
		count = long
	}
	for index, i := range l[len(l)-count:] {
		if i < r {
			r = i
			low_index = count - index - 1
		}
	}
	return low_index
}

func GetMin(l []float32, long int) float32 { //最低
	var r float32 = 999999
	count := len(l)
	if count > long {
		count = long
	}
	for _, i := range l[len(l)-count:] {
		if i < r {
			r = i
		}
	}
	return r
}

func GetMinAndShift(l []float32, long int) (float32, int) { //最低
	var r float32 = 999999
	var i int = len(l)
	count := i
	if count > long {
		count = long
	}
	for index, value := range l[len(l)-count:] {
		if value < r {
			r = value
			i = count - index - 1
		}
	}
	return r, i
}

func GetUpSum(l []float32, long int) (r float32) {
	count := len(l)
	if count > long {
		count = long
	}
	for _, i := range l[len(l)-count:] {
		if i > 0 {
			r += i
		}
	}
	return
}

func GetGrow(l []float32, shift int) float32 { //涨幅
	last := l[len(l)-1-shift-1]
	this := l[len(l)-1-shift]
	return (this - last) * 100 / last
}

func GetGrowPure(l []float32, shift int) float32 { //涨
	last := l[len(l)-1-shift-1]
	this := l[len(l)-1-shift]
	return (this - last)
}

func GetGrowPureIn(l []float32, a int, b int) float32 { //涨
	last := l[len(l)-1-a]
	this := l[len(l)-1-b]
	return (this - last)
}
