# Ginit
Welcome to ginit, a simple but useful tool for initializing your git repositories! With ginit, you can use .ginit files to make templates, which is stored in your .ginit folder. Then, you can load those templates, edit the template (for your repository name and stuff) and initialize in just one command!

Ginit is pretty fast sense its written in C, but it might not work on your operating system. Windows has no support, MacOS doesnt have any support but its unix based so it probably works (I cant test because I dont have a mac), but linux works best.

*Warning, this program is in very early development.*

Before compiling and running, make sure that in your home folder you have a .ginit folder. Inside of that, a templates and initcache folder. Example:

$HOME
--.ginit/
----initcache/
----templates/
    

The 4 main commands: add, pull, remove, and init. (Well really 5, but version doesnt really count)

Version command:
``` bash
ginit version
```

Firstly: Add. Adding is literally just adding a template. I will explain how write valid syntax for .ginit later. Example:

```bash
ginit add template1.ginit
```

Secondly: Pull. Pulling is just pulling a template to the directory you are in. Example:

```bash
ginit pull template1.ginit
```
Third: Remove. Removing is the opposite of add, it just removes a file. Example:
```bash
ginit remove template1.ginit
```

And lastly, the most important command, is init. Init is when the program turns .ginit into a sh script, and executes it. Example:

```bash
ginit init template1.ginit
```

## How to write valid syntax in .ginit
Very simple. There is no semicolons or anything like that. You just write it like an sh script (WITHOUT THE HEADER!)
but without the git part. Example:

```bash
init
remote add origin (your git server)
```

Also you can use string interpolation but its really basic right now. All you can really do is use the folder name, so I might add more later
Example of using it:

```bash
init
remote add origin git@github.com/ginit/*fn*.git
```
add a * at the start and a * at the end. Right now, fn means folder name.
Once there is enough of these I will make a seperate Markdown file for it.


Yeah, and thats about it. I am too lazy to write a whole new programming language when this works just fine.

