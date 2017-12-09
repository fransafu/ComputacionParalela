class CreateAsignacions < ActiveRecord::Migration[5.0]
  def change
    create_table :asignaciones do |t|
      t.integer :disponibilidad_sala_id
      t.integer :horario_id

      t.timestamps
    end
  end
end
