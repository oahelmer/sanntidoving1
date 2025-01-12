// Use `go run foo.go` to run your program

package main

import (
    . "fmt"
    "runtime"
    //"time"
)

var i = 0
const count = 1000000

func incrementing(inc chan int, done chan bool) {
    //TODO: increment i 1000000 times
    for j := 0; j < count; j++ {
        inc <- 1
    }
    close(inc)
    done <- true
}

func decrementing(dec chan int, done chan bool) {
    //TODO: decrement i 1000000 times
    for j := 0; j < count; j++ {
        dec <- -1
    }
    close(dec)
    done <- true
}

func main() {
    // What does GOMAXPROCS do? What happens if you set it to 1?
    runtime.GOMAXPROCS(2)   
    
    inc := make(chan int, 1000)
    dec := make(chan int, 1000)
    done := make(chan bool)
	
    // TODO: Spawn both functions as goroutines
	go incrementing(inc,done)
    go decrementing(dec,done)

    incDone, decDone := false, false

    // We have no direct way to wait for the completion of a goroutine (without additional synchronization of some sort)
    // We will do it properly with channels soon. For now: Sleep.
    for !incDone || !decDone {
        select {
        case msg, ok := <- inc:
            if ok{
                i += msg
            }else{
                incDone = true
            }
            
        case msg, ok := <- dec:
            if ok {
                i += msg
            }else{
                decDone = true
            }
        }
    }

    <- done
    <- done
    Println("The magic number is:", i)
}
