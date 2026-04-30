# Employee Management System (C++ Console App)

A console-based Employee Management System developed in C++ that allows managing employee records with full details, calculations, and file export support.

---

## Overview

This system is designed to simulate a basic HR management tool where you can:
- Add employees with full personal and professional data
- Store structured information using arrays and structs
- Calculate salaries based on working hours
- Display and search employee records
- Save data automatically into a CSV file

---

## Features

### 1. Employee Management
- Add new employee records
- Store:
  - Full Name (First, Middle, Last)
  - National ID
  - Contact Information (Email, Phone)
  - Address (Country, City, Street, Building No)
  - Gender
  - Marital Status
  - Working Hours

---

### 2. Salary System
- Salary is calculated based on working hours:
  - Normal rate for ≤ 24 hours
  - Higher rate for overtime (> 24 hours)

---

### 3. Data Display
- View all employees in structured format
- Search employee by ID (Code)
- Show detailed employee profile

---

### 4. File Handling
- Automatically saves employee data into `employees.csv`
- Includes headers for easy external analysis (Excel, etc.)

---

### 5. System Design
- Uses static arrays with max size = 1000 employees
- Uses Structs for data organization:
  - Name
  - Address
  - Contact Info
  - Employee Info
- Uses Enums for:
  - Gender (Male / Female)
  - Status (Married / Single / Widower)

---

## Tech Stack

- C++
- File Handling (fstream)
- Procedural + Structured Programming
- Enums & Structs

---

## Limitations

- Uses static arrays instead of dynamic memory or database
- No update/delete functionality for employees
- Console-based UI only

---

## Purpose

This project was built for learning purposes to practice:
- Structuring real-world data in C++
- File handling (CSV export)
- Building menu-driven applications
- Basic system design thinking

---

## Author

Tarek Mahmoud  
Computer Science Student | ICPC Trainee | C++ Developer
