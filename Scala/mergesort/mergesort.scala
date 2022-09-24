// If I remember correctly List is immutable in Scala and Sequence (Seq) is mutable.
// So keep that in mind if you use this. I'd have to relearn Scala to know the best practice.

// Merge with tail recursion
def merge_tail_recusion(left: List[Int], right: List[Int]): List[Int] = {
    // If Left is empty return right
    // If right is empty return left
    // recursive call with the smaller of the two heads
    (left, right) match {
        case (Nil, _) => right
        case (_, Nil) => left
        case (x :: xs, y :: ys) => if (x < y) x :: merge_tail_recusion(xs, right) else y :: merge_tail_recusion(left, ys)
    }
}

def merge_iterative(left: List[Int], right: List[Int]): List[Int] = {
    var result = List[Int]()

    var left1 = left
    var right1 = right

    while (left1.nonEmpty && right1.nonEmpty) {
        if (left1.head < right1.head) {
        result = result :+ left1.head
        left1 = left1.tail
        } 
        
        else {
        result = result :+ right1.head
        right1 = right1.tail
        }
    }
    result ++ left1 ++ right1
}

def merge_sort_iterative(unsorted: List[Int]): List[Int] = {
    var result = List[Int]()
    var unsorted1 = unsorted

    while (unsorted1.nonEmpty) {
        result = merge_iterative(result, List(unsorted1.head))
        unsorted1 = unsorted1.tail
    }
    result
}

def merge_sort_tail_recursive(unsorted: List[Int]): List[Int] = {
    unsorted match {
        case Nil => Nil // If empty list return empty list
        case x :: Nil => List(x)
        case _ => {
            val (left, right) = unsorted.splitAt(unsorted.length / 2)
            merge_tail_recusion(merge_sort_tail_recursive(left), merge_sort_tail_recursive(right))
        }
    }
}