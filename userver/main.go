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
	// user := User{
	// 	Name:      "jsphee",
	// 	Id:        1,
	// 	CreatedAt: time.Now(),
	// }

	usersInfo := ""

	for _, user := range gUsers {
		usersInfo += user.String()
	}

	w.Write([]byte(usersInfo))
}

func main() {
	fmt.Printf("Users: %v\n", gUsers)
	user1 := User{
		Name:      "jsphee",
		Id:        1,
		CreatedAt: time.Now(),
	}
	user2 := User{
		Name:      "jsphee2",
		Id:        2,
		CreatedAt: time.Now(),
	}
	gUsers = append(gUsers, user1, user2)
	fmt.Printf("Users: %v\n", gUsers)

	r := mux.NewRouter()
	// read
	r.HandleFunc("/user", GetUsers)
	// create
	r.HandleFunc("/user/:id", GetUsers)
	// jwt
	// put // post // update
	r.HandleFunc("/user/update/:id", GetUsers)
	// delete // remove
	// put // post // update
	r.HandleFunc("/user/remove/:id", GetUsers)

	log.Fatal(http.ListenAndServe(":8000", r))
}
