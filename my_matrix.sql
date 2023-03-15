--- SLISC SQLite data file for variables -----
--- similar to Matlab's mat file ---

CREATE TABLE VARS (
	ID    INTEGER PRIMARY KEY AUTOINCREMENT, -- never change once created
	NAME  TEXT    UNIQUE NOT NULL, -- can be renamed
	TYPE  INT     NOT NULL, -- reference TYPES table
	SHAPE TEXT, -- e.g.  '10 20 30', NULL for scalar
	DATA  BLOB, -- actual data, if NULL, then data is stored in another table named 'ID'
	DONE  INT, -- has all data finished writing?
	FOREIGN KEY (TYPE) REFERENCES TYPES (TYPE)
);

CREATE TABLE TYPES (
	TYPE INT  PRIMARY KEY, -- type number
	NAME TEXT UNIQUE -- UCHAR, CHAR, UINT8, INT8, INT64 ... , SINGLE, DOUBLE ...
);

INSERT INTO TYPES VALUES (0,  'Bool');
INSERT INTO TYPES VALUES (1,  'Char');
INSERT INTO TYPES VALUES (2,  'Int');
INSERT INTO TYPES VALUES (3,  'Llong');
INSERT INTO TYPES VALUES (11, 'Uchar');
INSERT INTO TYPES VALUES (12, 'Uint');
INSERT INTO TYPES VALUES (13, 'Ullong');
INSERT INTO TYPES VALUES (20, 'Float');
INSERT INTO TYPES VALUES (21, 'Doub');
INSERT INTO TYPES VALUES (22, 'Ldoub');
INSERT INTO TYPES VALUES (23, 'Qdoub');
INSERT INTO TYPES VALUES (40, 'Fcomp');
INSERT INTO TYPES VALUES (41, 'Comp');
INSERT INTO TYPES VALUES (42, 'Lcomp');
INSERT INTO TYPES VALUES (43, 'Qcomp');
INSERT INTO TYPES VALUES (60, 'Fimag');
INSERT INTO TYPES VALUES (61, 'Imag');
INSERT INTO TYPES VALUES (62, 'Limag');
INSERT INTO TYPES VALUES (63, 'Qimag');

----- Example Data -----

INSERT INTO VARS (NAME, TYPE, SHAPE, DATA, DONE) VALUES ('myBool', 0, NULL, 'a', 0);
UPDATE VARS SET DONE = 1 WHERE NAME = 'myBool';

INSERT INTO VARS (NAME, TYPE, SHAPE, DATA, DONE) VALUES ('myInt32', 2, NULL, 'w82h', 0);
UPDATE VARS SET DONE = 1 WHERE NAME = 'myInt32';

INSERT INTO VARS (NAME, TYPE, SHAPE, DATA, DONE) VALUES ('doub3D', 21, '2 4 3', 'a2d4q6f8e0w4r2h4k1h21q24', 0);
UPDATE VARS SET DONE = 1 WHERE NAME = 'doub3D';

INSERT INTO VARS (NAME, TYPE, SHAPE, DATA, DONE) VALUES ('myHuge', 41, '3 5 6 9 10 100', NULL, 0);

--- extra data table for 'doub6D' if BLOB cannot hold ---
CREATE TABLE '4' (
	ID     INTEGER PRIMARY KEY AUTOINCREMENT,
	DATA   BLOB -- 1GB max
);

INSERT INTO '4' VALUES (1, '1234567890');
INSERT INTO '4' VALUES (2, '1234567890');
INSERT INTO '4' VALUES (3, '1234');
UPDATE VARS SET DONE = 1 WHERE ID = 4;

-- get size ---
-- SELECT LENGTH(DATA) FROM 'myHuge'
-- SELECT COUNT(*) FROM 'myHuge'
