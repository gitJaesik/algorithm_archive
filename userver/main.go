package main

import (
	"fmt"
	"log"
	"net/http"
	"time"

	"github.com/gorilla/mux"
)

var gUsers Users

type User struct {
	Name string
	// Id        uuid.UUID
	Id        int
	CreatedAt time.Time
}

type Users []User

func (u User) String() string {
	return fmt.Sprintf("user name : %s, user createdAt : %v\n", u.Name, u.CreatedAt)
}

func GetUsers(w http.ResponseWriter, r *http.Request) {
	user := User{
		Name:      "jsphee",
		Id:        1,
		CreatedAt: time.Now(),
	}

	w.Write([]byte(user.String()))
}

func main() {

	r := mux.NewRouter()
	r.HandleFunc("/", GetUsers)

	log.Fatal(http.ListenAndServe(":8000", r))
}
