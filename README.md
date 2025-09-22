# Textbook Similarity Analyzer

This C++ project analyzes the similarity between multiple text files
(books) based on their **word frequency distributions**.\
It uses normalized word frequencies (ignoring stop words) and computes
the **cosine similarity** between pairs of books.

The program then identifies the **top 10 most similar pairs of books**.

------------------------------------------------------------------------

## 📂 Project Structure

-   **main.cpp** → The main program file (your provided code).
-   **book-Txt/** → A folder containing text files (`book1.txt`,
    `book2.txt`, ..., `book64.txt`).

------------------------------------------------------------------------

## ⚙️ Features

-   Reads and processes **multiple books** (default: 64 text files).
-   Converts all words to **uppercase** for uniformity.
-   Removes punctuation and filters out **common stop words** (`a`,
    `an`, `and`, `of`, `in`, `the`).
-   Computes **normalized word frequencies** for each book.
-   Calculates **cosine similarity** between all book pairs.
-   Displays the **Top 10 most similar book pairs**.

------------------------------------------------------------------------

## 🖥️ Requirements

-   A C++ compiler (e.g., GCC, Clang, MSVC).
-   Standard C++ libraries (`iostream`, `fstream`, `sstream`, `vector`,
    `algorithm`, `cctype`, `unordered_map`, `set`).

------------------------------------------------------------------------

## 🚀 How to Run

1.  **Clone the repository**:

    ``` bash
    git clone https://github.com/your-username/textbook-similarity-analyzer.git
    cd textbook-similarity-analyzer
    ```

2.  **Prepare the dataset**:

    -   Create a folder `book-Txt` in the project root.

    -   Place your text files inside it:

            book1.txt
            book2.txt
            ...
            book64.txt

3.  **Compile the program**:

    ``` bash
    g++ -o similarity main.cpp
    ```

4.  **Run the program**:

    ``` bash
    ./similarity
    ```

------------------------------------------------------------------------

## 📊 Output Example

    Top 10 similar pairs of textbooks:
    Book 5 and Book 12
    Book 8 and Book 9
    Book 15 and Book 22
    Book 1 and Book 7
    Book 14 and Book 20
    Book 2 and Book 3
    Book 11 and Book 16
    Book 19 and Book 25
    Book 6 and Book 10
    Book 4 and Book 13

------------------------------------------------------------------------

## 🔧 Customization

-   **Number of Books**: Change the `num_books` variable in `main()` if
    you have more or fewer files.
-   **File Path**: Update `folder_path` to match your text file
    directory.
-   **Stop Words**: Modify the `stop_words[]` array to include more
    words to ignore.

------------------------------------------------------------------------

## 📌 Future Improvements

-   Allow dynamic detection of the number of files in the folder.
-   Add command-line arguments for folder path and number of books.
-   Support additional stop words via an external file.
-   Save similarity results to an output file.

------------------------------------------------------------------------

## 📝 License

This project is licensed under the **MIT License** -- you're free to
use, modify, and distribute it.

------------------------------------------------------------------------

## 👨‍💻 Author

**Aaditya Raj Singhaniya**\
📍 Bareilly, Uttar Pradesh\
📧 <aadityaraj1473@gmail.com>\
💻 GitHub: [ars-0105](https://github.com/ars-0105)
