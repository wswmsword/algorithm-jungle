# Algorithm-Leaf

用 Common Lisp 描述算法，也存档其它语言的实现，这些存档将会用 Common Lisp 重写。

## Contribution

- 没有语言的限制；
- Common Lisp 代码遵循下方目录结构；
> Algorithm-Leaf/category-name/file-name.lisp
> 
> e.g Algorithm-Leaf/sorting/bubble-sort.lisp
- Common Lisp 以外的其它语言代码遵循下方目录结构；
> Algorithm-Leaf/Algorithm-Jungle/language-name/file-name.extension
> 
> e.g Algorithm-Leaf/Algorithm-Jungle/python/bubble-sort.py
- 算法的描述写在独立的 Markdown 文件中（至少包含简单描述、测试用例、有关链接），描述文件和对应算法文件同名；
- 当存在同一种算法的不同实现时，遵循下方文件后缀数位递增的规则；
> bubble-sort-digit.lisp
> 
> e.g bubble-sort.lisp bubble-sort-2.lisp bubble-sort-3.lisp
- 没有代码风格限制，这表示代码的排版不混乱并且仍有风格；
- 提交时参考下方提交信息；
> fix: A bug fix
> 
> feat: A new feature
> 
> docs: Documentation changes
> 
> test: Correct existing tests or add new ones
- 欢迎参与！

## Resources

- Repositories
	- [The Algorithms](https://github.com/TheAlgorithms)
	- [al-go-rithms](https://github.com/ZoranPandovski/al-go-rithms)
	- [cl-competitive](https://github.com/privet-kitty/cl-competitive)

## License

`Algorithm Leaf`采用 GPLv3 授权。