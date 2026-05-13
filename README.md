# 🎨 CS213 Assignment – Console Image Editor

![C++](https://img.shields.io/badge/Language-C++17-blue)
![Platform](https://img.shields.io/badge/Platform-Console-lightgrey)
![Status](https://img.shields.io/badge/Status-Completed-success)

A simple **console-based image editor** built in C++ for a CS213 assignment.
The program allows users to load images, apply filters interactively, and save the final result.

---

## 📌 Overview

This application is written in **C++** and relies on an external `Image` class (`Image_Class.h`) for:

* Loading images
* Pixel manipulation
* Saving edited images

💡 The user interacts with the program through a **text-based menu** in the terminal.

---

## ✨ Features

### 🖌️ Image Filters

* 🎞️ Grayscale conversion
* ⚫ Black & white filter
* 🔄 Color inversion
* ☀️ Brightness adjustment (darken/lighten)
* 🔁 Flip (horizontal & vertical)
* 🔃 Rotation (`90°`, `180°`, `270°`)
* 🌫️ Blur effect
* ✂️ Cropping
* 📏 Resizing
* 🔍 Edge detection

### 🖼️ Extra Features

* 🖼️ Add frames:

  * Simple frame
  * Double frame
  * Decorated frame
* 🔗 Merge with another image
* 💾 Save edited images

