class DefiniendoUnicidadesYValidacionesRestantes < ActiveRecord::Migration[5.0]
  def change
    change_column :departamentos, :nombre, :string, unique: true
    change_column :asignaturas, :codigo, :string, unique: true
    change_column :cursos, :codigo, :integer, unique: true
    add_index :cursos, [:asignatura_id, :semestre, :anio, :seccion], unique: true
    remove_column :salas, :sigla
    add_index :asignaciones, [:disponibilidad_sala_id, :horario_id], unique: true




  end
end
