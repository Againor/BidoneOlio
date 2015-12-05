package main

import (
	"appengine"
	"appengine/datastore"
	"net/http"
	"reflect"
)

func main() {
	fs := http.FileServer(http.Dir("static"))
	http.Handle("/", fs)
	http.ListenAndServe(":80", nil)
}

func creaBidone(w http.ResponseWriter, r *http.Response) {
	id := r.URL.Query().Get("id")
	long := r.URL.Query().Get("long")
	lati := r.URL.Query().Get("lati")
	level := r.URL.Query().Get("level")
	if id != nil && long != nil && lati != nil && level != nil {
		/*Tutti gli argomenti sono presenti ma non sappiamo se sono validi
		per controllarne la validità gli convertiamo in INT e FLOAT per le
		coordinate*/
		//TODO Controlla type degli argomenti e inserisci in un db
	}
	c := appengine.NewContext(r)
}

func impostaLivello(w http.ResponseWriter, r *http.Response) {
}

func trovaLivelli(w http.ResponseWriter, r *http.Response) {
}
