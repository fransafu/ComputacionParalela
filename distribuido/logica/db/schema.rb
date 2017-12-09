# This file is auto-generated from the current state of the database. Instead
# of editing this file, please use the migrations feature of Active Record to
# incrementally modify your database, and then regenerate this schema definition.
#
# Note that this schema.rb definition is the authoritative source for your
# database schema. If you need to create the application database on another
# system, you should be using db:schema:load, not running all the migrations
# from scratch. The latter is a flawed and unsustainable approach (the more migrations
# you'll amass, the slower it'll run and the greater likelihood for issues).
#
# It's strongly recommended that you check this file into your version control system.

ActiveRecord::Schema.define(version: 20170721165957) do

  # These are extensions that must be enabled in order to support this database
  enable_extension "plpgsql"

  create_table "acceso_paralelos", force: :cascade do |t|
    t.boolean  "disponible", default: true
    t.datetime "created_at",                null: false
    t.datetime "updated_at",                null: false
  end

  create_table "asignaciones", force: :cascade do |t|
    t.integer  "disponibilidad_sala_id"
    t.datetime "created_at",                null: false
    t.datetime "updated_at",                null: false
    t.integer  "horario_id"
    t.integer  "disponibilidad_docente_id"
  end

  create_table "asignaturas", force: :cascade do |t|
    t.string   "nombre"
    t.string   "codigo"
    t.integer  "departamento_id"
    t.integer  "creditos"
    t.integer  "horas_semanales"
    t.datetime "created_at",      null: false
    t.datetime "updated_at",      null: false
    t.index ["codigo"], name: "index_asignaturas_on_codigo", unique: true, using: :btree
  end

  create_table "cursos", force: :cascade do |t|
    t.integer  "codigo"
    t.integer  "asignatura_id"
    t.integer  "semestre"
    t.integer  "anio"
    t.integer  "seccion"
    t.integer  "docente_id"
    t.datetime "created_at",    null: false
    t.datetime "updated_at",    null: false
    t.index ["asignatura_id", "semestre", "anio", "seccion"], name: "index_cursos_on_asignatura_id_and_semestre_and_anio_and_seccion", unique: true, using: :btree
    t.index ["codigo"], name: "index_cursos_on_codigo", unique: true, using: :btree
  end

  create_table "departamentos", force: :cascade do |t|
    t.string   "nombre"
    t.integer  "facultad_id"
    t.datetime "created_at",  null: false
    t.datetime "updated_at",  null: false
    t.index ["nombre"], name: "index_departamentos_on_nombre", unique: true, using: :btree
  end

  create_table "disponibilidad_docentes", force: :cascade do |t|
    t.integer  "docente_id"
    t.integer  "periodo_id"
    t.string   "dia"
    t.datetime "created_at", null: false
    t.datetime "updated_at", null: false
  end

  create_table "disponibilidad_salas", force: :cascade do |t|
    t.integer  "sala_id"
    t.string   "dia"
    t.integer  "periodo_id"
    t.boolean  "libre",      default: true
    t.datetime "created_at",                null: false
    t.datetime "updated_at",                null: false
  end

  create_table "docentes", force: :cascade do |t|
    t.string   "nombres"
    t.string   "apellidos"
    t.string   "rut"
    t.integer  "departamento_id"
    t.string   "email"
    t.datetime "created_at",      null: false
    t.datetime "updated_at",      null: false
    t.integer  "bloques"
  end

  create_table "facultades", force: :cascade do |t|
    t.string   "sigla"
    t.string   "nombre"
    t.datetime "created_at", null: false
    t.datetime "updated_at", null: false
  end

  create_table "horarios", force: :cascade do |t|
    t.string   "dia"
    t.integer  "curso_id"
    t.integer  "periodo_id"
    t.datetime "created_at",                null: false
    t.datetime "updated_at",                null: false
    t.boolean  "libre",      default: true
  end

  create_table "periodos", force: :cascade do |t|
    t.integer  "numero"
    t.string   "inicio"
    t.string   "termino"
    t.datetime "created_at", null: false
    t.datetime "updated_at", null: false
  end

  create_table "salas", force: :cascade do |t|
    t.integer  "capacidad"
    t.string   "nombre"
    t.string   "tipo"
    t.datetime "created_at", null: false
    t.datetime "updated_at", null: false
  end

  create_table "users", force: :cascade do |t|
    t.string   "email"
    t.string   "password"
    t.datetime "created_at", null: false
    t.datetime "updated_at", null: false
  end

  create_table "usuarios", force: :cascade do |t|
    t.string   "rut"
    t.string   "password"
    t.datetime "created_at", null: false
    t.datetime "updated_at", null: false
  end

  add_foreign_key "asignaciones", "disponibilidad_docentes"
  add_foreign_key "asignaciones", "disponibilidad_salas"
  add_foreign_key "asignaciones", "horarios"
  add_foreign_key "asignaturas", "departamentos"
  add_foreign_key "cursos", "asignaturas"
  add_foreign_key "cursos", "docentes"
  add_foreign_key "departamentos", "facultades", column: "facultad_id"
  add_foreign_key "disponibilidad_docentes", "docentes"
  add_foreign_key "disponibilidad_docentes", "periodos"
  add_foreign_key "disponibilidad_salas", "periodos"
  add_foreign_key "disponibilidad_salas", "salas"
  add_foreign_key "docentes", "departamentos"
  add_foreign_key "horarios", "cursos"
  add_foreign_key "horarios", "periodos"
end
