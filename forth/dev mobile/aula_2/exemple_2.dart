import "package:flutter/material.dart";

void main() {
  runApp(
    MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          backgroundColor: Colors.lightBlueAccent,
          title: Text(
            "Minha app Bar",
          ),
        ),
        body: Center(
          child: Column(
            children:[
              Icon(Icons.bathtub),
              Text("First row"),
              Icon(Icons.anchor),
              Text("Second row"),
              Icon(Icons.restaurant),
              Text("Last row"),
              Row(
                mainAxisAlignment: MainAxisAlignment.center,
                children: [
                  Text("First Row"),
                  Text("Second Row"),
                  Text("Last row")
                ],
              ),
            ],
          ),
        ),
        floatingActionButton: FloatingActionButton(
          onPressed: () {
            // print("Botao pressionado"); // function for debugging, not for final user
          },
          child: const Icon(Icons.accessible_rounded),
        ),
      ),
    ),
  );
}