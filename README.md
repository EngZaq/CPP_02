# C++ Module 02: Fixed-Point Numbers

## 📚 Overview
This project is part of the 42 C++ curriculum (Module 02). It involves creating a robust **Fixed-Point Number** class in C++98 to handle numbers with fractional parts without the precision loss or performance overhead of standard floating-point types (`float`, `double`).

The goal is to master three key C++ concepts:
1.  **Ad-hoc Polymorphism** (Function Overloading)
2.  **Operator Overloading**
3.  **Orthodox Canonical Class Form** (OCF)

## 🛠 Features
The `Fixed` class is fully compliant with the **Orthodox Canonical Form** and implements the following features:

* **Fixed-Point Representation:** Uses a standard integer to store the raw value and **8 bits** for the fractional part.
* **Constructors:**
    * `Fixed(void)`: Initializes value to 0.
    * `Fixed(const int)`: Converts an integer to fixed-point.
    * `Fixed(const float)`: Converts a float to fixed-point.
    * `Fixed(const Fixed &)`: Copy constructor.
* **Converters:**
    * `toInt(void)`: Converts fixed-point to integer.
    * `toFloat(void)`: Converts fixed-point to float.
* **Operator Overloading:**
    * **Assignment:** `=`
    * **Comparison:** `>`, `<`, `>=`, `<=`, `==`, `!=`
    * **Arithmetic:** `+`, `-`, `*`, `/`
    * **Increment/Decrement:** Pre and Post `++`, `--` (increments by smallest representable $\epsilon$).
    * **Stream Insertion:** `<<` (allows printing `Fixed` objects directly to output streams).
* **Static Utilities:**
    * `min`: Returns the smaller of two references.
    * `max`: Returns the larger of two references.

## 📂 Project Structure

| Exercise | Directory | Description | Key Concepts |
| :--- | :--- | :--- | :--- |
| **Ex00** | `ex00/` | Basic Class Structure | OCF, `getRawBits`, `setRawBits`. |
| **Ex01** | `ex01/` | Useful Numbers | `Int`/`Float` constructors, `toInt`, `toFloat`, `operator<<`. |
| **Ex02** | `ex02/` | Operator Overloading | Comparisons, Arithmetic (`+`, `-`, `*`, `/`), Increment/Decrement. |

## ⚙️ Technical Implementation

### 1. The Fixed-Point Math
The class uses a 32-bit `int` to store the value. We reserve **8 bits** for the fraction.
$$Value_{fixed} = Value_{real} \times 256$$

* **Int to Fixed:** Bitwise left shift by 8 (`n << 8`).
    * *Example:* $1 \to 256$
* **Float to Fixed:** Multiply by 256 and round to the nearest integer.
    * *Example:* $1.5 \to \text{round}(1.5 \times 256) = 384$
* **Fixed to Int:** Bitwise right shift by 8 (`n >> 8`).
* **Fixed to Float:** Divide the raw integer value by 256.0.

### 2. Operator Overloading Logic
We overload operators to make `Fixed` objects behave like native types.

* **Arithmetic (`+`, `-`, `*`, `/`):**
    Operations are performed by converting operands to `float`, executing the math, and converting back to `Fixed`. This prevents overflow and precision loss during intermediate steps.
    ```cpp
    Fixed Fixed::operator*(const Fixed &rhs) const {
        return Fixed(this->toFloat() * rhs.toFloat());
    }
    ```

* **Comparison (`>`, `<`, `==`, etc.):**
    Since both numbers share the same scale (8 fractional bits), we directly compare the raw integer values for maximum performance.

* **Increment/Decrement (`++`, `--`):**
    We distinguish between **Pre** (`++i`) and **Post** (`i++`) increment using a dummy `int` parameter.
    * *Pre-increment:* Modifies the object and returns a reference to it.
    * *Post-increment:* Creates a copy, modifies the original, and returns the copy.

## 🚀 How to Run

**1. Compilation**
Each exercise directory (`ex00`, `ex01`, `ex02`) contains a `Makefile`. To compile a specific exercise, navigate to its folder and run:
```bash
make
```

**2. Execution Run the compiled executable:

```bash

./fixed
```
3. Cleanup To remove object files and executables:

```bash

make fclean
```
