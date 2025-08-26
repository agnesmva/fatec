import "package:flutter/material.dart";



void main() {
  runApp(
    MaterialApp(
      home: Scaffold(
        body: Center(
          child: Container(
            decoration: BoxDecoration(
              color: Colors.white,
              borderRadius: BorderRadius.all(
               Radius.circular(18.0)
              ),
              boxShadow: [
                BoxShadow(
                  color: Colors.red,
                  offset: Offset(-5, -5)
                ),
              ],
              border: Border.all(
                color: Colors.indigo,
                width: 3,
              ),
            ),
            child: Padding(
              padding: const EdgeInsets.all(16), 
              child: Text("Meu app em flutter"),
            ),
          ),
        ),
      ),
    ),
  );
}