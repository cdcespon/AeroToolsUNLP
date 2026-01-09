-- Tabla: usuarios
CREATE TABLE IF NOT EXISTS usuarios (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    legajo TEXT UNIQUE NOT NULL,
    nombre TEXT,
    tipo TEXT CHECK(tipo IN ('alumno', 'docente', 'investigador')),
    email TEXT,
    carrera TEXT,
    año_ingreso INTEGER,
    primera_visita DATETIME DEFAULT CURRENT_TIMESTAMP,
    ultima_actividad DATETIME DEFAULT CURRENT_TIMESTAMP,
    total_calculos INTEGER DEFAULT 0
);

CREATE INDEX IF NOT EXISTS idx_usuarios_legajo ON usuarios(legajo);

-- Tabla: calculos_superficies (Updated for Cesium/KML)
CREATE TABLE IF NOT EXISTS calculos_superficies (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    usuario_id INTEGER REFERENCES usuarios(id),
    tipo_superficie TEXT,
    parametros TEXT, -- JSON
    coordenadas TEXT, -- JSON coordinates
    ubicacion_geo TEXT, -- JSON {lat, lon, alt}
    area_total REAL,
    volumen REAL,
    fecha_calculo DATETIME DEFAULT CURRENT_TIMESTAMP,
    notas TEXT
);

-- Tabla: mediciones_viento
CREATE TABLE IF NOT EXISTS mediciones_viento (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    estacion TEXT NOT NULL,
    fecha_medicion DATETIME NOT NULL,
    direccion INTEGER,
    velocidad REAL,
    temperatura REAL,
    usuario_id INTEGER REFERENCES usuarios(id),
    fuente TEXT
);

-- Tabla: perfiles_alares
CREATE TABLE IF NOT EXISTS perfiles_alares (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    usuario_id INTEGER REFERENCES usuarios(id),
    nombre_perfil TEXT,
    tipo TEXT,
    coordenadas TEXT, -- JSON
    fecha_creacion DATETIME DEFAULT CURRENT_TIMESTAMP
);

-- Tabla: simulaciones_trayectoria
CREATE TABLE IF NOT EXISTS simulaciones_trayectoria (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    usuario_id INTEGER REFERENCES usuarios(id),
    tipo_simulacion TEXT,
    parametros TEXT, -- JSON
    trayectoria_kml TEXT, -- Storing KML snippet or reference
    fecha_simulacion DATETIME DEFAULT CURRENT_TIMESTAMP
);
