@ Due to the way mks4agb (Nintendo's tool) works, key split table labels can
@ appear before the actual start of the key split table data. If you look at
@ the first keysplit table (KeySplitTable1), you'll notice it's offset backwards
@ by 36 bytes. This is because the key split tables don't map instruments
@ for the entire note range (0-127)--they only map subsets, and the upper
@ and lower ranges aren't necessarily 0 or 127.
@
@ For example if a key split table maps an note range of 10-20, then the key
@ split table label will be offset 10 bytes before the actual key split data
@ begins. Therefore, the notes naturally map to the key split table without
@ any extra offset calculation.

.set KeySplitTable1, . - 36
	.byte 0  @ 36
	.byte 0  @ 37
	.byte 0  @ 38
	.byte 0  @ 39
	.byte 0  @ 40
	.byte 0  @ 41
	.byte 0  @ 42
	.byte 0  @ 43
	.byte 0  @ 44
	.byte 0  @ 45
	.byte 0  @ 46
	.byte 0  @ 47
	.byte 0  @ 48
	.byte 0  @ 49
	.byte 0  @ 50
	.byte 0  @ 51
	.byte 0  @ 52
	.byte 0  @ 53
	.byte 0  @ 54
	.byte 1  @ 55
	.byte 1  @ 56
	.byte 1  @ 57
	.byte 1  @ 58
	.byte 1  @ 59
	.byte 1  @ 60
	.byte 1  @ 61
	.byte 1  @ 62
	.byte 1  @ 63
	.byte 1  @ 64
	.byte 1  @ 65
	.byte 1  @ 66
	.byte 1  @ 67
	.byte 1  @ 68
	.byte 1  @ 69
	.byte 2  @ 70
	.byte 2  @ 71
	.byte 2  @ 72
	.byte 2  @ 73
	.byte 2  @ 74
	.byte 2  @ 75
	.byte 2  @ 76
	.byte 2  @ 77
	.byte 2  @ 78
	.byte 2  @ 79
	.byte 2  @ 80
	.byte 2  @ 81
	.byte 2  @ 82
	.byte 2  @ 83
	.byte 2  @ 84
	.byte 2  @ 85
	.byte 2  @ 86
	.byte 2  @ 87
	.byte 2  @ 88
	.byte 2  @ 89
	.byte 2  @ 90
	.byte 3  @ 91
	.byte 3  @ 92
	.byte 3  @ 93
	.byte 3  @ 94
	.byte 3  @ 95
	.byte 3  @ 96
	.byte 3  @ 97
	.byte 3  @ 98
	.byte 3  @ 99
	.byte 3  @ 100
	.byte 3  @ 101
	.byte 3  @ 102
	.byte 3  @ 103
	.byte 3  @ 104
	.byte 3  @ 105
	.byte 3  @ 106
	.byte 3  @ 107

.set KeySplitTable2, . - 36
	.byte 0  @ 36
	.byte 0  @ 37
	.byte 0  @ 38
	.byte 0  @ 39
	.byte 0  @ 40
	.byte 0  @ 41
	.byte 0  @ 42
	.byte 0  @ 43
	.byte 0  @ 44
	.byte 0  @ 45
	.byte 0  @ 46
	.byte 0  @ 47
	.byte 0  @ 48
	.byte 0  @ 49
	.byte 0  @ 50
	.byte 0  @ 51
	.byte 0  @ 52
	.byte 0  @ 53
	.byte 0  @ 54
	.byte 0  @ 55
	.byte 0  @ 56
	.byte 0  @ 57
	.byte 0  @ 58
	.byte 0  @ 59
	.byte 0  @ 60
	.byte 0  @ 61
	.byte 0  @ 62
	.byte 0  @ 63
	.byte 0  @ 64
	.byte 0  @ 65
	.byte 0  @ 66
	.byte 0  @ 67
	.byte 0  @ 68
	.byte 1  @ 69
	.byte 1  @ 70
	.byte 1  @ 71
	.byte 1  @ 72
	.byte 1  @ 73
	.byte 1  @ 74
	.byte 1  @ 75
	.byte 1  @ 76
	.byte 1  @ 77
	.byte 1  @ 78
	.byte 1  @ 79
	.byte 1  @ 80
	.byte 2  @ 81
	.byte 2  @ 82
	.byte 2  @ 83
	.byte 2  @ 84
	.byte 2  @ 85
	.byte 2  @ 86
	.byte 2  @ 87
	.byte 2  @ 88
	.byte 2  @ 89
	.byte 2  @ 90
	.byte 2  @ 91
	.byte 2  @ 92
	.byte 2  @ 93
	.byte 2  @ 94
	.byte 2  @ 95
	.byte 2  @ 96
	.byte 2  @ 97
	.byte 2  @ 98
	.byte 2  @ 99
	.byte 2  @ 100
	.byte 2  @ 101
	.byte 2  @ 102
	.byte 2  @ 103
	.byte 2  @ 104
	.byte 2  @ 105
	.byte 2  @ 106
	.byte 2  @ 107

.set KeySplitTable3, . - 36
	.byte 0  @ 36
	.byte 0  @ 37
	.byte 0  @ 38
	.byte 0  @ 39
	.byte 0  @ 40
	.byte 0  @ 41
	.byte 0  @ 42
	.byte 0  @ 43
	.byte 0  @ 44
	.byte 0  @ 45
	.byte 0  @ 46
	.byte 0  @ 47
	.byte 0  @ 48
	.byte 0  @ 49
	.byte 0  @ 50
	.byte 0  @ 51
	.byte 0  @ 52
	.byte 0  @ 53
	.byte 0  @ 54
	.byte 0  @ 55
	.byte 0  @ 56
	.byte 0  @ 57
	.byte 0  @ 58
	.byte 0  @ 59
	.byte 0  @ 60
	.byte 0  @ 61
	.byte 0  @ 62
	.byte 0  @ 63
	.byte 0  @ 64
	.byte 0  @ 65
	.byte 1  @ 66
	.byte 1  @ 67
	.byte 1  @ 68
	.byte 1  @ 69
	.byte 1  @ 70
	.byte 1  @ 71
	.byte 1  @ 72
	.byte 1  @ 73
	.byte 1  @ 74
	.byte 1  @ 75
	.byte 1  @ 76
	.byte 1  @ 77
	.byte 1  @ 78
	.byte 1  @ 79
	.byte 1  @ 80
	.byte 1  @ 81
	.byte 1  @ 82
	.byte 1  @ 83
	.byte 2  @ 84
	.byte 2  @ 85
	.byte 2  @ 86
	.byte 2  @ 87
	.byte 2  @ 88
	.byte 2  @ 89
	.byte 2  @ 90
	.byte 2  @ 91
	.byte 2  @ 92
	.byte 2  @ 93
	.byte 2  @ 94
	.byte 2  @ 95
	.byte 2  @ 96
	.byte 2  @ 97
	.byte 2  @ 98
	.byte 2  @ 99
	.byte 2  @ 100
	.byte 2  @ 101
	.byte 2  @ 102
	.byte 2  @ 103
	.byte 2  @ 104
	.byte 2  @ 105
	.byte 2  @ 106
	.byte 2  @ 107

.set KeySplitTable4, . - 24
	.byte 0  @ 24
	.byte 0  @ 25
	.byte 0  @ 26
	.byte 0  @ 27
	.byte 0  @ 28
	.byte 0  @ 29
	.byte 0  @ 30
	.byte 0  @ 31
	.byte 0  @ 32
	.byte 0  @ 33
	.byte 0  @ 34
	.byte 0  @ 35
	.byte 0  @ 36
	.byte 0  @ 37
	.byte 0  @ 38
	.byte 0  @ 39
	.byte 0  @ 40
	.byte 0  @ 41
	.byte 1  @ 42
	.byte 1  @ 43
	.byte 1  @ 44
	.byte 1  @ 45
	.byte 1  @ 46
	.byte 1  @ 47
	.byte 1  @ 48
	.byte 1  @ 49
	.byte 1  @ 50
	.byte 1  @ 51
	.byte 1  @ 52
	.byte 1  @ 53
	.byte 1  @ 54
	.byte 1  @ 55
	.byte 1  @ 56
	.byte 1  @ 57
	.byte 1  @ 58
	.byte 1  @ 59
	.byte 1  @ 60
	.byte 1  @ 61
	.byte 1  @ 62
	.byte 1  @ 63
	.byte 1  @ 64
	.byte 1  @ 65
	.byte 1  @ 66
	.byte 1  @ 67
	.byte 1  @ 68
	.byte 1  @ 69
	.byte 1  @ 70
	.byte 1  @ 71
	.byte 1  @ 72
	.byte 1  @ 73
	.byte 1  @ 74
	.byte 1  @ 75
	.byte 1  @ 76
	.byte 1  @ 77
	.byte 1  @ 78
	.byte 1  @ 79
	.byte 1  @ 80
	.byte 1  @ 81
	.byte 1  @ 82
	.byte 1  @ 83
	.byte 1  @ 84
	.byte 1  @ 85
	.byte 1  @ 86
	.byte 1  @ 87
	.byte 1  @ 88
	.byte 1  @ 89
	.byte 1  @ 90
	.byte 1  @ 91
	.byte 1  @ 92
	.byte 1  @ 93
	.byte 1  @ 94
	.byte 1  @ 95
	.byte 1  @ 96
	.byte 1  @ 97
	.byte 1  @ 98
	.byte 1  @ 99
	.byte 1  @ 100
	.byte 1  @ 101
	.byte 1  @ 102
	.byte 1  @ 103
	.byte 1  @ 104
	.byte 1  @ 105
	.byte 1  @ 106
	.byte 1  @ 107

.set KeySplitTable5, . - 36
	.byte 0  @ 36
	.byte 0  @ 37
	.byte 0  @ 38
	.byte 0  @ 39
	.byte 0  @ 40
	.byte 0  @ 41
	.byte 0  @ 42
	.byte 0  @ 43
	.byte 0  @ 44
	.byte 0  @ 45
	.byte 0  @ 46
	.byte 0  @ 47
	.byte 0  @ 48
	.byte 0  @ 49
	.byte 0  @ 50
	.byte 0  @ 51
	.byte 0  @ 52
	.byte 0  @ 53
	.byte 0  @ 54
	.byte 0  @ 55
	.byte 0  @ 56
	.byte 0  @ 57
	.byte 0  @ 58
	.byte 0  @ 59
	.byte 0  @ 60
	.byte 0  @ 61
	.byte 0  @ 62
	.byte 0  @ 63
	.byte 0  @ 64
	.byte 0  @ 65
	.byte 1  @ 66
	.byte 1  @ 67
	.byte 1  @ 68
	.byte 1  @ 69
	.byte 1  @ 70
	.byte 1  @ 71
	.byte 1  @ 72
	.byte 1  @ 73
	.byte 1  @ 74
	.byte 1  @ 75
	.byte 1  @ 76
	.byte 1  @ 77
	.byte 1  @ 78
	.byte 1  @ 79
	.byte 1  @ 80
	.byte 1  @ 81
	.byte 1  @ 82
	.byte 1  @ 83
	.byte 1  @ 84
	.byte 1  @ 85
	.byte 1  @ 86
	.byte 1  @ 87
	.byte 1  @ 88
	.byte 1  @ 89
	.byte 1  @ 90
	.byte 1  @ 91
	.byte 1  @ 92
	.byte 1  @ 93
	.byte 1  @ 94
	.byte 1  @ 95
	.byte 1  @ 96
	.byte 1  @ 97
	.byte 1  @ 98
	.byte 1  @ 99
	.byte 1  @ 100
	.byte 1  @ 101
	.byte 1  @ 102
	.byte 1  @ 103
	.byte 1  @ 104
	.byte 1  @ 105
	.byte 1  @ 106
	.byte 1  @ 107


.set KeySplitTable6, . - 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 1
	.byte 1
	.byte 1
	.byte 2
	.byte 2
	.byte 3
	.byte 3
	.byte 4
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 6
	.byte 6
	.byte 6
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 8
	.byte 8
	.byte 9
	.byte 9
	.byte 9
	.byte 10
	.byte 10
	.byte 10
	.byte 10
	.byte 11
	.byte 12
	.byte 12
	.byte 12
	.byte 13
	.byte 13
	.byte 13
	.byte 13
	.byte 14
	.byte 14
	.byte 14
	.byte 15
	.byte 15
	.byte 15
	.byte 15
	.byte 16
	.byte 16
	.byte 16
	.byte 17
	.byte 17
	.byte 17
	.byte 17
	.byte 18
	.byte 18
	.byte 18
	.byte 19
	.byte 19
	.byte 19
	.byte 19
	.byte 20
	.byte 20
	.byte 21
	.byte 21
	.byte 21
	.byte 22
	.byte 22
	.byte 22
	.byte 22
	.byte 23
	.byte 23
	.byte 23
	.byte 23
	.byte 23
	.byte 23
	.byte 23
	.byte 23
	.byte 23
	.byte 23
	.byte 23
	.byte 23
	.byte 23
	.byte 23
	.byte 23
	.byte 23
	.byte 23
	.byte 23
	.byte 23
	.byte 23
	.byte 23
	.byte 23
	.byte 23

.set KeySplitTable7, . - 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 1
	.byte 1
	.byte 1
	.byte 2
	.byte 2
	.byte 2
	.byte 3
	.byte 3
	.byte 3
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 5
	.byte 6
	.byte 6
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 8
	.byte 8
	.byte 8
	.byte 8
	.byte 8
	.byte 8
	.byte 9
	.byte 10
	.byte 10
	.byte 10
	.byte 10
	.byte 10
	.byte 11
	.byte 11
	.byte 11
	.byte 11
	.byte 11
	.byte 12
	.byte 12
	.byte 12
	.byte 13
	.byte 13
	.byte 13
	.byte 13
	.byte 13
	.byte 13
	.byte 13
	.byte 13
	.byte 13
	.byte 14
	.byte 14
	.byte 14
	.byte 14
	.byte 14
	.byte 14
	.byte 14
	.byte 14
	.byte 14
	.byte 14
	.byte 14
	.byte 14
	.byte 14
	.byte 14
	.byte 14
	.byte 14
	.byte 14
	.byte 14
	.byte 14
	.byte 14

.set KeySplitTable8, . - 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 3
	.byte 3
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 5
	.byte 5
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 7
	.byte 7
	.byte 7
	.byte 8
	.byte 8
	.byte 8
	.byte 8
	.byte 8
	.byte 8
	.byte 8
	.byte 8
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9

.set KeySplitTable9, . - 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 1
	.byte 1
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 3
	.byte 3
	.byte 3
	.byte 4
	.byte 4
	.byte 4
	.byte 5
	.byte 5
	.byte 6
	.byte 6
	.byte 6
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 8
	.byte 8
	.byte 8
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 10
	.byte 10
	.byte 10
	.byte 10
	.byte 11
	.byte 12
	.byte 12
	.byte 13
	.byte 14
	.byte 14
	.byte 14
	.byte 14
	.byte 14
	.byte 15
	.byte 15
	.byte 16
	.byte 17
	.byte 17
	.byte 17
	.byte 17
	.byte 17
	.byte 17
	.byte 17
	.byte 17
	.byte 17
	.byte 17
	.byte 17
	.byte 17
	.byte 17
	.byte 17
	.byte 17
	.byte 17
	.byte 17
	.byte 17
	.byte 17
	.byte 17
	.byte 17
	.byte 17
	.byte 17
	.byte 17
	.byte 17
	.byte 17
	.byte 17

.set KeySplitTable10, . - 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 5
	.byte 5
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7

.set KeySplitTable11, . - 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 2
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5

.set KeySplitTable12, . - 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4

.set KeySplitTable13, . - 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 2
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 4
	.byte 4
	.byte 4
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 7
	.byte 7
	.byte 7
	.byte 8
	.byte 8
	.byte 8
	.byte 8
	.byte 8
	.byte 8
	.byte 8
	.byte 8
	.byte 8
	.byte 9
	.byte 9
	.byte 10
	.byte 10
	.byte 11
	.byte 11
	.byte 11
	.byte 11
	.byte 11
	.byte 11
	.byte 11
	.byte 12
	.byte 12
	.byte 13
	.byte 13
	.byte 13
	.byte 13
	.byte 13
	.byte 13
	.byte 13
	.byte 14
	.byte 14
	.byte 14
	.byte 14
	.byte 14
	.byte 14
	.byte 14
	.byte 14
	.byte 14
	.byte 14
	.byte 14
	.byte 14
	.byte 14
	.byte 14
	.byte 14
	.byte 14
	.byte 14
	.byte 14
	.byte 14
	.byte 14
	.byte 14
	.byte 14
	.byte 14
	.byte 14
	.byte 14

.set KeySplitTable14, . - 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 3
	.byte 3
	.byte 3
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7

.set KeySplitTable15, . - 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 2
	.byte 2
	.byte 2
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4

.set KeySplitTable16, . - 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 2
	.byte 2
	.byte 3
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4

.set KeySplitTable17, . - 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 3
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 5
	.byte 5
	.byte 5
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7

.set KeySplitTable18, . - 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 1
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 3
	.byte 3
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6

.set KeySplitTable19, . - 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 2
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 4
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 6
	.byte 6
	.byte 7
	.byte 7
	.byte 8
	.byte 8
	.byte 8
	.byte 8
	.byte 9
	.byte 10
	.byte 11
	.byte 12
	.byte 13
	.byte 13
	.byte 13
	.byte 13
	.byte 14
	.byte 14
	.byte 14
	.byte 14
	.byte 14
	.byte 15
	.byte 15
	.byte 15
	.byte 16
	.byte 16
	.byte 17
	.byte 17
	.byte 18
	.byte 18
	.byte 18
	.byte 18
	.byte 19
	.byte 19
	.byte 19
	.byte 20
	.byte 20
	.byte 21
	.byte 21
	.byte 22
	.byte 22
	.byte 23
	.byte 23
	.byte 23
	.byte 23
	.byte 23
	.byte 23
	.byte 23
	.byte 23
	.byte 23
	.byte 23
	.byte 23
	.byte 23
	.byte 23
	.byte 23
	.byte 23
	.byte 23
	.byte 23
	.byte 23
	.byte 23
	.byte 23
	.byte 23
	.byte 23
	.byte 23
	.byte 23
	.byte 23
	.byte 23

.set KeySplitTable20, . - 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 2
	.byte 2
	.byte 2
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 4
	.byte 4
	.byte 5
	.byte 5
	.byte 5
	.byte 6
	.byte 6
	.byte 6
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 8
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 10
	.byte 10
	.byte 11
	.byte 11
	.byte 11
	.byte 12
	.byte 12
	.byte 12
	.byte 12
	.byte 12
	.byte 12
	.byte 13
	.byte 13
	.byte 14
	.byte 14
	.byte 14
	.byte 15
	.byte 15
	.byte 15
	.byte 15
	.byte 15
	.byte 15
	.byte 15
	.byte 15
	.byte 15
	.byte 15
	.byte 15
	.byte 15
	.byte 15
	.byte 15
	.byte 15
	.byte 15
	.byte 15
	.byte 15
	.byte 15
	.byte 15
	.byte 15
	.byte 15
	.byte 15
	.byte 15
	.byte 15

.set KeySplitTable21, . - 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 1
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 3
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 6
	.byte 7
	.byte 8
	.byte 8
	.byte 8
	.byte 8
	.byte 8
	.byte 9
	.byte 9
	.byte 10
	.byte 11
	.byte 11
	.byte 11
	.byte 11
	.byte 12
	.byte 12
	.byte 12
	.byte 12
	.byte 13
	.byte 13
	.byte 13
	.byte 13
	.byte 13
	.byte 14
	.byte 14
	.byte 15
	.byte 16
	.byte 16
	.byte 16
	.byte 16
	.byte 17
	.byte 17
	.byte 17
	.byte 18
	.byte 18
	.byte 18
	.byte 18
	.byte 18
	.byte 18
	.byte 18
	.byte 19
	.byte 19
	.byte 19
	.byte 19
	.byte 19
	.byte 19
	.byte 19
	.byte 19
	.byte 19
	.byte 19
	.byte 19
	.byte 19
	.byte 19
	.byte 19
	.byte 19
	.byte 19
	.byte 19
	.byte 19
	.byte 19
	.byte 19
	.byte 19
	.byte 19
	.byte 19
	.byte 19

.set KeySplitTable22, . - 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 3
	.byte 4
	.byte 4
	.byte 5
	.byte 5
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 7
	.byte 7
	.byte 8
	.byte 9
	.byte 10
	.byte 10
	.byte 10
	.byte 10
	.byte 11
	.byte 12
	.byte 12
	.byte 12
	.byte 13
	.byte 13
	.byte 13
	.byte 13
	.byte 14
	.byte 14
	.byte 14
	.byte 14
	.byte 15
	.byte 15
	.byte 16
	.byte 16
	.byte 17
	.byte 17
	.byte 17
	.byte 17
	.byte 18
	.byte 18
	.byte 18
	.byte 18
	.byte 18
	.byte 19
	.byte 19
	.byte 19
	.byte 19
	.byte 20
	.byte 21
	.byte 21
	.byte 21
	.byte 21
	.byte 21
	.byte 21
	.byte 21
	.byte 21
	.byte 21
	.byte 21
	.byte 21
	.byte 21
	.byte 21
	.byte 21
	.byte 21
	.byte 21
	.byte 21
	.byte 21
	.byte 21
	.byte 21
	.byte 21

.set KeySplitTable23, . - 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 4
	.byte 4
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7

.set KeySplitTable24, . - 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 3
	.byte 3
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 6
	.byte 6
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 8
	.byte 8
	.byte 8
	.byte 8
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9

.set KeySplitTable25, . - 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 4
	.byte 5
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 8
	.byte 8
	.byte 9
	.byte 9
	.byte 9
	.byte 10
	.byte 11
	.byte 12
	.byte 12
	.byte 13
	.byte 13
	.byte 13
	.byte 13
	.byte 14
	.byte 15
	.byte 15
	.byte 15
	.byte 16
	.byte 16
	.byte 16
	.byte 16
	.byte 16
	.byte 16
	.byte 16
	.byte 17
	.byte 18
	.byte 18
	.byte 18
	.byte 19
	.byte 19
	.byte 19
	.byte 19
	.byte 20
	.byte 21
	.byte 21
	.byte 21
	.byte 21
	.byte 21
	.byte 21
	.byte 22
	.byte 22
	.byte 22
	.byte 23
	.byte 24
	.byte 24
	.byte 24
	.byte 24
	.byte 24
	.byte 24
	.byte 24
	.byte 24
	.byte 24
	.byte 24
	.byte 24
	.byte 24
	.byte 24
	.byte 24
	.byte 24
	.byte 24
	.byte 24
	.byte 24
	.byte 24
	.byte 24
	.byte 24

.set KeySplitTable26, . - 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 3
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 6
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 8
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 10
	.byte 10
	.byte 10
	.byte 11
	.byte 11
	.byte 11
	.byte 11
	.byte 11
	.byte 12
	.byte 12
	.byte 13
	.byte 13
	.byte 13
	.byte 13
	.byte 13
	.byte 14
	.byte 15
	.byte 15
	.byte 15
	.byte 15
	.byte 15
	.byte 15
	.byte 15
	.byte 15
	.byte 15
	.byte 16
	.byte 16
	.byte 16
	.byte 16
	.byte 16
	.byte 16
	.byte 16
	.byte 16
	.byte 16
	.byte 16
	.byte 16
	.byte 16
	.byte 16
	.byte 16
	.byte 16
	.byte 16
	.byte 16
	.byte 16
	.byte 16
	.byte 16
	.byte 16
	.byte 16
	.byte 16
	.byte 16

.set KeySplitTable27, . - 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 2
	.byte 3
	.byte 3
	.byte 3
	.byte 4
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 6
	.byte 7
	.byte 8
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 10
	.byte 11
	.byte 11
	.byte 12
	.byte 13
	.byte 13
	.byte 14
	.byte 15
	.byte 15
	.byte 15
	.byte 16
	.byte 16
	.byte 17
	.byte 17
	.byte 18
	.byte 18
	.byte 19
	.byte 19
	.byte 19
	.byte 20
	.byte 20
	.byte 21
	.byte 22
	.byte 22
	.byte 22
	.byte 22
	.byte 22
	.byte 22
	.byte 22
	.byte 22
	.byte 22
	.byte 22
	.byte 22
	.byte 22
	.byte 22
	.byte 22
	.byte 22
	.byte 22
	.byte 22
	.byte 22
	.byte 22
	.byte 22
	.byte 22
	.byte 22
	.byte 22
	.byte 22

.set KeySplitTable28, . - 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 1
	.byte 2
	.byte 2
	.byte 2
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6

.set KeySplitTable29, . - 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 1
	.byte 1
	.byte 1
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 5
	.byte 5
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 7
	.byte 7
	.byte 8
	.byte 8
	.byte 8
	.byte 8
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9

.set KeySplitTable30, . - 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 3
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 6
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 8
	.byte 9
	.byte 9
	.byte 10
	.byte 10
	.byte 10
	.byte 10
	.byte 10
	.byte 11
	.byte 11
	.byte 11
	.byte 12
	.byte 12
	.byte 12
	.byte 12
	.byte 13
	.byte 13
	.byte 13
	.byte 14
	.byte 14
	.byte 15
	.byte 15
	.byte 16
	.byte 16
	.byte 16
	.byte 16
	.byte 16
	.byte 16
	.byte 16
	.byte 16
	.byte 16
	.byte 16
	.byte 16
	.byte 16
	.byte 16
	.byte 16
	.byte 16
	.byte 16
	.byte 16
	.byte 16
	.byte 16
	.byte 16
	.byte 16
	.byte 16
	.byte 16
	.byte 16
	.byte 16
	.byte 16
	.byte 16
	.byte 16

.set KeySplitTable31, . - 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 2
	.byte 2
	.byte 2
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5

.set KeySplitTable32, . - 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 3
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5

.set KeySplitTable33, . - 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 3
	.byte 3
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4

.set KeySplitTable34, . - 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 1
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 3
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4

.set KeySplitTable35, . - 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 0
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 1
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 2
	.byte 3
	.byte 3
	.byte 3
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 4
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 5
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 6
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 7
	.byte 8
	.byte 8
	.byte 8
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	.byte 9
	