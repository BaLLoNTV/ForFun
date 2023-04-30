package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	var N, X, Y int
	var tmp string
	var arr [][]rune
	reader := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	fmt.Fscan(reader, &N)
	for i := 0; i < N; i++ {
		tmpArr := make([][]rune, 1)
		tmpArr[0] = make([]rune, 0)
		X = 0
		Y = 0
		fmt.Fscan(reader, &tmp)
		//fmt.Printf("start: %s", tmp)
		for _, ch := range tmp {

			fmt.Fprintf(out, "\nX %d Y %d\n", X, Y)
			fmt.Fprintf(out, "input %c\n", ch)
			for g := range tmpArr {
				for _, h := range tmpArr[g] {
					fmt.Fprintf(out, "%c", h)
				}
				fmt.Fprintln(out)
			}
			if ch == 'N' {

				//fmt.Printf("%c", 'N')

				tmpArr = append(tmpArr[:Y+1], tmpArr[Y:]...)
				tmpArr[Y+1] = tmpArr[Y][X:]
				tmpArr[Y] = tmpArr[Y][:X]
				X = 0
				Y++
				continue
			}
			if ch == 'L' {

				//fmt.Printf("%c", 'L')

				if X > 0 {
					X--
				}
				continue
			}
			if ch == 'R' {

				//fmt.Printf("%c", 'R')

				if X != len(tmpArr[Y]) {
					X++
				}
				continue
			}
			if ch == 'U' {

				//fmt.Printf("%c", 'U')

				if Y == 0 {
					continue
				}
				if X > len(tmpArr[Y-1]) {
					X = len(tmpArr[Y-1])
				}
				Y--
				continue
			}
			if ch == 'D' {

				//fmt.Printf("%c", 'D')

				if Y >= len(tmpArr)-1 {
					continue
				}
				if X > len(tmpArr[Y+1]) {
					X = len(tmpArr[Y+1])
				}
				Y++
				continue
			}
			if ch == 'B' {

				//fmt.Printf("%c", 'B')

				X = 0
				continue
			}
			if ch == 'E' {

				//fmt.Printf("%c", 'E')

				X = len(tmpArr[Y])
				continue
			}
			if X == len(tmpArr[Y]) {

				//fmt.Printf("%c", 'M')

				tmpArr[Y] = append(tmpArr[Y], ch)
				X++

				fmt.Fprintf(out, "\n to end \n")
				for g := range tmpArr {
					for _, h := range tmpArr[g] {
						fmt.Fprintf(out, "%c", h)
					}
					fmt.Fprintln(out)
				}

				continue
			}
			if X == 0 {

				//fmt.Printf("%c", 'm')
				//fmt.Fprintf(out, "\n before begin \n")
				//for g := range tmpArr {
				//	for _, h := range tmpArr[g] {
				//		fmt.Fprintf(out, "%c", h)
				//	}
				//	fmt.Fprintln(out)
				//}

				tmpArr[Y] = append([]rune{ch}, tmpArr[Y]...)
				X++

				//fmt.Fprintf(out, "\n to begin \n")
				//for g := range tmpArr {
				//	for _, h := range tmpArr[g] {
				//		fmt.Fprintf(out, "%c", h)
				//	}
				//	fmt.Fprintln(out)
				//}
				continue
			}
			//fmt.Printf("%c", 'o')
			fmt.Fprintf(out, "\nX %d Y %d\n", X, Y)
			fmt.Fprintf(out, "\n before in mid \n")
			for g := range tmpArr {
				for _, h := range tmpArr[g] {
					fmt.Fprintf(out, "%c", h)
				}
				fmt.Fprintln(out)
			}
			fmt.Fprintf(out, "\nX %d Y %d\n", X, Y)
			tmpArr[Y] = append(tmpArr[Y], ' ')
			for g := range tmpArr {
				for _, h := range tmpArr[g] {
					fmt.Fprintf(out, "%c", h)
				}
				fmt.Fprintln(out)
			}
			//tmpArr[Y] = append(tmpArr[Y][:X+1], tmpArr[Y][X:]...)
			copy(tmpArr[Y][X+1:], tmpArr[Y][X:])
			for g := range tmpArr {
				for _, h := range tmpArr[g] {
					fmt.Fprintf(out, "%c", h)
				}
				fmt.Fprintln(out)
			}
			tmpArr[Y][X] = ch
			fmt.Fprintf(out, "\nX %d Y %d\n", X, Y)
			for g := range tmpArr {
				for _, h := range tmpArr[g] {
					fmt.Fprintf(out, "%c", h)
				}
				fmt.Fprintln(out)
			}
			X++
			fmt.Fprintf(out, "\nX %d Y %d\n", X, Y)
			fmt.Fprintf(out, "\n in mid \n")
			for g := range tmpArr {
				for _, h := range tmpArr[g] {
					fmt.Fprintf(out, "%c", h)
				}
				fmt.Fprintln(out)
			}
		}

		for k := range tmpArr {
			arr = append(arr, tmpArr[k])
		}
		arr = append(arr, []rune{'-'})
	}
	for o := range arr {
		for _, v := range arr[o] {
			fmt.Fprintf(out, "%c", v)
		}
		fmt.Fprintln(out)
	}
}
