       0: 13 01 01 fa  	addi	sp, sp, -96
       4: 23 3c 11 04  	sd	ra, 88(sp)
       8: 23 38 81 04  	sd	s0, 80(sp)
       c: 13 04 01 06  	addi	s0, sp, 96
      10: 23 34 a4 fe  	sd	a0, -24(s0)
      14: 23 30 b4 fe  	sd	a1, -32(s0)
      18: 03 35 84 fe  	ld	a0, -24(s0)
      1c: 23 3c a4 fa  	sd	a0, -72(s0)
      20: 03 35 84 fb  	ld	a0, -72(s0)
      24: 03 35 05 00  	ld	a0, 0(a0)
      28: 23 3c a4 fc  	sd	a0, -40(s0)
      2c: 03 35 84 fb  	ld	a0, -72(s0)
      30: 03 35 85 00  	ld	a0, 8(a0)
      34: 23 38 a4 fc  	sd	a0, -48(s0)
      38: 03 35 84 fb  	ld	a0, -72(s0)
      3c: 03 35 05 01  	ld	a0, 16(a0)
      40: 23 34 a4 fc  	sd	a0, -56(s0)
      44: 03 35 84 fb  	ld	a0, -72(s0)
      48: 03 35 85 01  	ld	a0, 24(a0)
      4c: 23 30 a4 fc  	sd	a0, -64(s0)
      50: 03 35 84 fd  	ld	a0, -40(s0)
      54: 83 35 04 fe  	ld	a1, -32(s0)
      58: 93 95 25 00  	slli	a1, a1, 2
      5c: 33 05 b5 00  	add	a0, a0, a1
      60: 03 25 05 00  	lw	a0, 0(a0)
      64: 23 2a a4 fa  	sw	a0, -76(s0)
      68: 03 35 04 fd  	ld	a0, -48(s0)
      6c: 83 35 04 fe  	ld	a1, -32(s0)
      70: 93 95 25 00  	slli	a1, a1, 2
      74: 33 05 b5 00  	add	a0, a0, a1
      78: 03 25 05 00  	lw	a0, 0(a0)
      7c: 23 28 a4 fa  	sw	a0, -80(s0)
      80: 03 35 84 fc  	ld	a0, -56(s0)
      84: 83 35 04 fe  	ld	a1, -32(s0)
      88: 93 95 25 00  	slli	a1, a1, 2
      8c: 33 05 b5 00  	add	a0, a0, a1
      90: 03 25 05 00  	lw	a0, 0(a0)
      94: 23 26 a4 fa  	sw	a0, -84(s0)
      98: 03 25 44 fb  	lw	a0, -76(s0)
      9c: 83 25 04 fb  	lw	a1, -80(s0)
      a0: 3b 05 b5 02  	mulw	a0, a0, a1
      a4: 83 25 c4 fa  	lw	a1, -84(s0)
      a8: 3b 05 b5 00  	addw	a0, a0, a1
      ac: 23 24 a4 fa  	sw	a0, -88(s0)
      b0: 03 25 84 fa  	lw	a0, -88(s0)
      b4: 83 35 04 fc  	ld	a1, -64(s0)
      b8: 03 36 04 fe  	ld	a2, -32(s0)
      bc: 13 16 26 00  	slli	a2, a2, 2
      c0: b3 85 c5 00  	add	a1, a1, a2
      c4: 23 a0 a5 00  	sw	a0, 0(a1)
      c8: 13 05 00 00  	li	a0, 0
      cc: 83 30 81 05  	ld	ra, 88(sp)
      d0: 03 34 01 05  	ld	s0, 80(sp)
      d4: 13 01 01 06  	addi	sp, sp, 96
      d8: 67 80 00 00  	ret
