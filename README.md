![QueltiLock.Logo](https://i.ibb.co/fFkMKH2/Quelti-Shapka.png)

This project is designed to better protect passwords and personal data locally. Wish me luck in the development of the project;)

# Install
1. Download the latest release of QueltiLock
2. Install Visual C++ (a suitable version is supplied with the release)
3. Move ``QueltiLock.exe`` and ``config.json`` to any convenient folder
4. Run ``QueltiLock.exe``

# About
Some time ago I decided to create my own encryption method. At first it was a simple script that made decryption impossible without 3 files. Soon I started to further improve the algorithm, and after half a year I completely rewrote the encryption algorithm three times. A year later I created **QLTP**, a method that cannot be cracked using bruteforce, frequency analysis, and other popular cracking methods. It is a symmetric encryption method that uses a password and a number of alphabets as a key. The decryption of the text depends on them. The higher the number of alphabets, the longer decryption and encryption will take. More details about this method are written somewhere below:) Its main advantages are that it cannot be cracked using bruteforce. Therefore, it is perfect for protecting information on local computers.

## List of functions
- Text encryption
- Text decryption
- File encryption
- File decryption

## QLTP - Quelti protection

Advantage  | Disadvantage
----------------|----------------------
Protection against brute force attacks | You need to use the same random method when encrypting and decrypting
Changing the encryption and decryption speed | Problems may arise when using unsuitable algorithms

### Advantage
You can decide yourself on how many alphabets will be generated when encrypting. By default, 2048 alphabets are generated, but you can change this value yourself as an additional security measure when encrypting. If the wrong number of alphabets is entered when decrypting, the key generation range will change, which will affect the decryption result. This is also an excellent protection against brute force, as with a value of 1 000 000, decrypting one message can take quite a long time. Note that a large number of alphabets takes up more RAM.

### Disadvantage
To implement this technology, I use std::mt19937, which generates numbers based on the password received as a result of hashing. The problem is that when using different random methods, we can get completely different values even if the password matches.

# How to Use
### Step 1
Choose whether you want to encrypt something or decrypt it.

![1](https://i.ibb.co/gJsdPM7/tutorial0.jpg)

### Step 2
Select which encryption mode you need.

![2](https://i.ibb.co/JnkNYN5/tutorial1.jpg)

### Step 3
Enter the message you want to encrypt or decrypt. (the picture shows an example of encryption)

![3](https://i.ibb.co/0FWFZHf/tutorial2.jpg)

### Step 4
Enter the password that will be used to encrypt or decrypt the message.

![4](https://i.ibb.co/vhX8yCd/tutorial3.jpg)

### Step 5
Enter the number of alphabets to encrypt. This is optional, if you omit it the default value of 2048 alphabets will be selected

![5](https://i.ibb.co/YT9nKC5/tutorial4.jpg)

### Step 6
That's great! Here's your message.

![6](https://i.ibb.co/yNptn2T/tutorial5.jpg)

# Errors
<details> <summary>Error 1</summary>
The file "config.json" is not found.
Check if there is a config.json file in the folder with the exe file. You can download it in the release.
</details>

<details> <summary>Error 2</summary>
Error in config.json file. Alphabet configuration error.
The alphabet must be at least 5 characters.
</details>

<details> <summary>Error 3</summary>
Error in config.json file. Animation parameter error.
Only "true" or "false" values are allowed.
</details>

<details> <summary>Error 4</summary>
Error in config.json file. Error in language selection.
Only available values: "en", "ru", "uk".
</details>

<details> <summary>Error 5</summary>
Error in config.json. Error setlocale().
Only available values: "en", "ru", "uk".
</details>

<details> <summary>Errors 6, 7</summary>
If you have these errors, contact the developer or try reinstalling the program.
</details>
