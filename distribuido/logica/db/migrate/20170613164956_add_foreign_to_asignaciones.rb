class AddForeignToAsignaciones < ActiveRecord::Migration[5.0]
  def change
    add_foreign_key :asignaciones , :disponibilidad_salas, column: :disponibilidad_sala_id, primary_key: :id
    add_foreign_key :asignaciones , :horarios, column: :horario_id, primary_key: :id

  end
end
