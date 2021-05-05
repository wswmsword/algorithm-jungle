;; quicksort classic
(defun quicksort (vec l r)
  (let ((i l)
        (j r)
        (p (svref vec (round (+ l r) 2)))) ; pivot
    (while (<= i j)
      (while (< (svref vec i) p) (incf i))
      (while (> (svref vec j) p) (decf j))
      (when (<= i j)
        (rotatef (svref vec i) (svref vec j))
        (incf i)
        (decf j)))
    (if (>= (- j l) 1) (quicksort vec l j))
    (if (>= (- r i) 1) (quicksort vec i r)))
  vec)

;; quicksort-3way
;; https://stackoverflow.com/a/20896833
(defun quicksort-3way (arr start end)
  "Quick sort body"
  (if (< start end)
      (let ((n-pair (partition arr start end)))
        (quicksort-3way arr start (car n-pair))
        (quciksort-3way arr (cdr n-pair) end))))

(defun partition (arr start end)
  "Partition according to pivot."
  (let ((pivot (aref arr start)) (cur start))
    (loop while (<= start end) do
      (cond
        ((< pivot (aref arr start))
         (swap arr start end)
         (decf end))
        ((> pivot (aref arr start))
         (swap arr cur start)
         (incf cur)
         (incf start))
        (t
         (incf start))))
    (cons (decf cur) start)))

(defun swap (arr i j)
  "Swap element of arr"
  (let ((tmp (aref arr i)))
    (setf (aref arr i) (aref arr j))
    (setf (aref arr j) tmp)))
